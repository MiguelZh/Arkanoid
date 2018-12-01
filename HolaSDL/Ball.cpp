#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Vector2D.h"
#include "Ball.h"
#include "Game.h"
//Ball::Ball(Texture * textura, Vector2D coord, uint ancho, uint alto){}


void Ball::update() {
	
	//coord = coord + vel;
	Vector2D collVector;
	SDL_Rect destRect = getRect();
	if (game->collides(destRect, collVector, vel)) {

		vel.normalize(); collVector.normalize();

		vel = vel - (collVector*(2 * (vel*collVector)));	
	}
	coord = coord + vel;
}
void Ball::resetBall() {
	if (coord.getY() > 570 && vidas >0) {
		coord = { 390,450 };
		//vel = { 0.2,0.2 };
		vidas--;
	}
}
void Ball::nuevoNv() {
	coord = { 390,450 };
	//vel = { 0.02,0.02 };
}
