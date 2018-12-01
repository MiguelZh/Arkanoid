#include"ArkanoidObject.h"

ArkanoidObject::~ArkanoidObject(){}

SDL_Rect  ArkanoidObject::getRect() {
	SDL_Rect destRect;
	destRect.x = coord.getX();
	destRect.y = coord.getY();
	destRect.h = h;
	destRect.w = w;
	return destRect;
}
void ArkanoidObject::render() {
	SDL_Rect destRect = getRect();
	textura->render(destRect, SDL_FLIP_NONE);
}
void ArkanoidObject::loadFromFile(string filename) {

}
void ArkanoidObject::saveToFile() {

}