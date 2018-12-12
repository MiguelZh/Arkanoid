#pragma once
#include "SDL_image.h"
#include "Texture.h"
#include "checkML.h"

const int MENU_WIDTH = 800;
const int MENU_HEIGHT = 600;

class Menu {
private:
	const enum textureName { titleText, playButtonText, quitText, loadButtonText };

	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	SDL_Rect titleRect;
	Texture * titleTexture = nullptr;
	SDL_Rect playButtonRect;
	Texture * playTexture = nullptr;
	SDL_Rect QuitRect;
	Texture * quitTexture = nullptr;
	SDL_Rect loadButtonRect;
	Texture * loadTexture = nullptr;
	bool exit = false;
public:
	~Menu();
	Menu();
	void render();
	void update();
	void handleEvents();
	void run();
};