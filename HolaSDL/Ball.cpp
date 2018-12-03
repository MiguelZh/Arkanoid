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
	coord = coord + velocidad;
	if (game->collides(destRect, collVector, velocidad)) { // llama al collides del game

		velocidad.normalize();

		velocidad = velocidad - (collVector*(2 * (velocidad*collVector)));	
	}

}
void Ball::resetBall() {
	if (coord.getY() > 570 && vidas >0) {
		coord = { 390,450 };
		vidas--;
	}
}
void Ball::nuevoNv() {
	coord = { 390,450 };
}
