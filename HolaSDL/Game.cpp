
#include "SDL.h"
#include "SDL_image.h"
#include "checkML.h"
#include <iostream>
#include "Game.h"



using namespace std;
Game::Game() {
	
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Hola", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";


	string nombre [5]= {"ball","bricks","paddle","topside","side"}; // nombre de las imagenes
		for (uint i = 0; i < NUM_TEXTURES; i++) // array strings direcciones
		{
			textures[i] = new Texture(renderer); //
			try
			{
				textures[i]->load("..//images//" + nombre[i] + ".png");
			}
			catch (string s) {
				s = "no se encontro la imagen";
				throw s;
			}
			
		}
	// WallTop
	double x= 0, y=0;
	Vector2D vectorWallTop(x, y);
	//wallTop = new Wall(textures[3],vectorWallTop, WIN_WIDTH,15);
	wallTop = new Wall(WIN_WIDTH, 15, vectorWallTop, textures[3], "Top");
	//WallDer
	double xIzq = WIN_WIDTH - 18, yIzq = 0;
	Vector2D vectorWallIzq(xIzq, yIzq);
	wallDer = new Wall(15, WIN_HEIGHT, vectorWallIzq, textures[4], "Left");
	//WallIzq
	wallIzq = new Wall(15, WIN_HEIGHT, vectorWallTop, textures[4], "Right");
	//paddle
	double xP = 370, yP = 550;
	Vector2D vectorPaddle(xP, yP);
	//paddle = new Paddle(textures[2], vectorPaddle, 70, 20);
	paddle = new Paddle(75, 15, vectorPaddle, textures[2], velocidad);
	//bola
	double xB = 390, yB = 500;
	Vector2D vectorBola(xB, yB);
	//bola = new Ball(textures[0], vectorBola,velocidad, 20,20,this);
	bola = new Ball(20, 20, vectorBola, textures[0], velocidad, this);
	//blocksmap
	//mapa = new BlocksMap(WIN_WIDTH,WIN_HEIGHT-200); // alto y ancho del bloque
	mapa = new BlocksMap(WIN_WIDTH, WIN_HEIGHT , textures[1]);
	mapa->LeerFichero(niveles[0]);
	
}

Game::~Game() {
	for (uint i = 0; i < NUM_TEXTURES; i++) { delete textures[i]; }
	delete wallTop;delete wallDer;delete wallIzq;
	delete paddle;
	delete bola;
	delete mapa;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Game::run() {
	velocidad.normalize();
	while (!exit) {
		uint start = SDL_GetTicks();
		handleEvents();
		update();
		render();
		uint frameTime = SDL_GetTicks() - start;
		if (frameTime < FRAME_RATE)
			SDL_Delay(FRAME_RATE - frameTime);
	}
}

void Game::update() {
	int i= 1;
	bola->update();
	bola->resetBall();
	if (mapa->pasoNivel()&& i<=2) {
		mapa->LeerFichero(niveles[i]);
		bola->nuevoNv();
		i++;
	}
}

void Game::render() const {
	SDL_RenderClear(renderer);
	wallTop->render();
	wallDer->render();
	wallIzq->render();
	paddle->render();
	bola->render();
	mapa->render();
	SDL_RenderPresent(renderer);
	
}

void Game::handleEvents() {
	SDL_Event event;
	while (SDL_PollEvent(&event) && !exit) {
		if (event.type == SDL_QUIT) exit = true;
		paddle->handleEvents(event);
	}
}
bool Game::collides(const SDL_Rect destRect, Vector2D &collVector, const Vector2D &vel) {

	if(mapa->detectCollision(destRect,collVector,vel)) return true;
	if (wallDer->collides(destRect, collVector)) return true;
	if (wallIzq->collides(destRect, collVector)) return true;
	if (wallTop->collides(destRect, collVector)) return true;
	if (paddle->collides(destRect, collVector)) return true;

	return false;
}