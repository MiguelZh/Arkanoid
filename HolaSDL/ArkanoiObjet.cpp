#include"ArkanoidObjet.h"

ArkanoidObjet::~ArkanoidObjet(){}
ArkanoidObjet::ArkanoidObjet(){}

SDL_Rect * ArkanoidObjet::getRect() {
	SDL_Rect destRect;
	destRect.x = coord.getX();
	destRect.y = coord.getY();
	destRect.h = h;
	destRect.w = w;
	return &destRect;
}