#include"Menu.h"
#include"Game.h"
Menu::Menu() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Hola", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		MENU_WIDTH, MENU_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (window == nullptr || renderer == nullptr) throw "Error loading the SDL window or renderer";

	string nombre[4] = { "..\\images\\title.png", "..\\images\\playButton.png", "..\\images\\loadButton.png",
	"..\\images\\quit.png", }; // nombre de las imagenes


	titleRect.x = 200;
	titleRect.y = 60;
	titleRect.w = 400;
	titleRect.h = 200;
	titleTexture = new Texture(renderer);
	titleTexture->load(nombre[0]);

	playButtonRect.x = 100;
	playButtonRect.y = 400;
	playButtonRect.w = playButtonRect.h = 100;
	playTexture = new Texture(renderer);
	playTexture->load(nombre[1]);

	loadButtonRect.x = 600;
	loadButtonRect.y = 400;
	loadButtonRect.w = loadButtonRect.h = 100;
	loadTexture = new Texture(renderer);
	loadTexture->load(nombre[2]);

	QuitRect.x = 350;
	QuitRect.y = 500;
	QuitRect.w = QuitRect.h = 50;
	quitTexture = new Texture(renderer);
	quitTexture->load(nombre[3]);
}
void Menu::run() {
	while (!exit) {
		handleEvents();
		update();
		render();
	}
}
void Menu::render() {
	SDL_RenderClear(renderer);
	titleTexture->render(titleRect, SDL_FLIP_NONE);
	playTexture->render(playButtonRect, SDL_FLIP_NONE);
	loadTexture->render(loadButtonRect, SDL_FLIP_NONE);
	quitTexture->render(QuitRect, SDL_FLIP_NONE);
	SDL_RenderPresent(renderer);
}
void Menu::update() {

}
void Menu::handleEvents() {
	SDL_Event E;
	SDL_PollEvent(&E);
	if (E.type == SDL_MOUSEBUTTONDOWN) {
		int x, y;
		SDL_GetMouseState(&x, &y);
		if (x < titleRect.w / 2) {
			Game game;
			game.run();
			exit = true;
		}
	}
}