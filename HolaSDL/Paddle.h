#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Vector2D.h"
#include "math.h"
#include <iostream>
#include "MovingObject.h"
class Paddle:public MovingObject {
private:
	SDL_Event E; 
public:
	Paddle(int ancho, int alto, Vector2D coord, Texture * textura, Vector2D vel) :
		MovingObject(ancho, alto, coord, textura, vel) {			}

	void modificaPos(int num,bool dir);
	void handleEvents(SDL_Event &E);
	bool collides(const SDL_Rect destRect, Vector2D &collVector);
	Vector2D ballhitPaddle(const SDL_Rect * ballrect);
	void reset();
	void alargar();
	void acortar();

};