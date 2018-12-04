
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


	string nombre [NUM_TEXTURES]= { "..\\images\\bricks.png", "..\\images\\rewards.png", "..\\images\\side.png",
		"..\\images\\topside.png", "..\\images\\paddle.png", "..\\images\\ball.png" }; // nombre de las imagenes

		textures[blocksMapText] = new Texture(renderer);
		textures[blocksMapText]->load(nombre[blocksMapText], 2, 3);
		textures[rewardText] = new Texture(renderer);
		textures[rewardText]->load(nombre[rewardText], 10, 8);
		for (int i = 2; i < NUM_TEXTURES; i++) {
			textures[i] = new Texture(renderer);
			textures[i]->load(nombre[i], 1, 1);
		}
	// WallTop
	wallTop = new Wall(WIN_WIDTH+30, 15, Vector2D(-15,0), textures[topWallText], "Top");
	//WallDer
	double xIzq = WIN_WIDTH - 18, yIzq = 0;
	Vector2D vectorWallIzq(xIzq, yIzq);
	wallDer = new Wall(15, WIN_HEIGHT, Vector2D(WIN_WIDTH-15,0), textures[sideWallText], "Right");
	//WallIzq
	wallIzq = new Wall(15, WIN_HEIGHT, Vector2D(0,0), textures[sideWallText], "Left");
	//paddle
	double xP = 370, yP = 550; paddleWidth = 75;
	Vector2D vectorPaddle(xP, yP);
	paddle = new Paddle(paddleWidth , 15, vectorPaddle, textures[paddleText], velocidad);
	//bola
	double xB = 390, yB = 500;
	Vector2D vectorBola(xB, yB);
	bola = new Ball(20, 20, vectorBola, textures[ballText], velocidad, this);
	//blocksmap
	mapa = new BlocksMap(WIN_WIDTH, WIN_HEIGHT , textures[blocksMapText]);
	mapa->LeerFichero(niveles[0]);
	nivelActual++;
	rellenaVector();
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

	if (reward != nullptr) { reward->update(); }
	bola->update();
	if (mapa->pasoNivel()&& nivelActual<=2) {
		mapa->LeerFichero(niveles[nivelActual]);
		bola->nuevoNv();
		nivelActual++;
	}
}

void Game::render() const {
	SDL_RenderClear(renderer);
	mapa->render();
	for (int i = 0; i < objects.size(); i++) {
		objects[i]->render();
	}
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
	SDL_Rect d = paddle->getRect();
	if(mapa->detectCollision(destRect,collVector,vel,this)) return true;
	if (wallDer->collides(destRect, collVector)) return true;
	if (wallIzq->collides(destRect, collVector)) return true;
	if (wallTop->collides(destRect, collVector)) return true;
	if (paddle->collides(destRect, collVector)) return true;
	return false;
}
Paddle* Game:: getPaddle() {
	return paddle;
}

void Game::spawnReward(Vector2D coord) {
	srand(time(NULL));
	int type = rand() % 4;
	reward = new Reward(50, 30, coord, textures[rewardText], Vector2D(0, 2),type, this);
	objects.push_back(reward);
}
void Game::rellenaVector() {
	objects.push_back(paddle);
	objects.push_back(bola);
	objects.push_back(wallTop);
	objects.push_back(wallDer);
	objects.push_back(wallIzq);
}
void Game::rewardMasNivel() {
	if (nivelActual < 3) {
		uint width = mapa->getW();
		uint height = mapa->getH();
		delete mapa;
		mapa = new BlocksMap(width, height, textures[blocksMapText]);
		mapa->LeerFichero(niveles[nivelActual]);
		nivelActual++;
	}
}
void Game::destruyeReward() {
	objects.pop_back();
	delete(reward);
	reward = nullptr;
}
void Game::reset() {
	paddle->setW(75);
}
void Game::acortar() {
	reset();
	paddle->setW(paddle->getW()/1.5);
}
void Game::alargar() {
	reset();
	paddle->setW(paddle->getW()*2);
}
void Game::masVida() {
	vidas++;
}
void Game::menosVida() {
	vidas--;
}
int Game::getVidas() {
	return vidas;
}
