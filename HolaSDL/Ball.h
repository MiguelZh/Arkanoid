#pragma once
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Vector2D.h"
#include "math.h"
#include <iostream>
#include"MovingObject.h"
class Game;
class Ball : public MovingObject{
private:
	Game * game; int vidas = 3;
public:
	Ball(uint ancho, uint alto,Vector2D coord, Texture * textura, Vector2D vel, Game * g) :
		MovingObject(ancho,alto,coord,textura,vel), game(g) {}
	void update();
	void resetBall();
	void nuevoNv();
	void masVida() { vidas++; };
};