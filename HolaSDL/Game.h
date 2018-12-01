#ifndef GameH
#define GameH

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Ball.h"
#include "Block.h"
#include "BlocksMap.h"
#include "Paddle.h"
#include "Texture.h"
#include "Vector2D.h"
#include "Wall.h"

#include <string>

using namespace std;

typedef unsigned int uint;

const uint WIN_WIDTH = 800;
const uint WIN_HEIGHT = 600;
const uint NUM_TEXTURES = 5;
const uint FRAME_RATE = 6;

class Game {
private:
	Vector2D velocidad = Vector2D(1, -1);
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Ball * bola = nullptr;
	Block * bloque = nullptr;
	BlocksMap * mapa = nullptr;
	Paddle * paddle = nullptr;
	Wall * wallTop = nullptr,* wallDer = nullptr,* wallIzq = nullptr;
	bool exit = false;
	bool gameOver = false;
	bool win = false;
	Texture* textures[NUM_TEXTURES];
	string niveles[3] = { "..//maps//level02.ark","..//maps//level02.ark","..//maps//level03.ark" };

public:
	Game();
	~Game();
	void run();
	void render() const;
	void handleEvents();
	void update();
	bool collides(const SDL_Rect destRect, Vector2D &collVector, const Vector2D &vel);
};
#endif