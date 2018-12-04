#include"ArkanoidObject.h"

ArkanoidObject::~ArkanoidObject()
{
	textura = nullptr;
}
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
void ArkanoidObject::renderFrame(uint row,uint col) {
	SDL_Rect destRect = getRect();
	textura->renderFrame(destRect,row ,col, 0, SDL_FLIP_NONE);
}
void ArkanoidObject::loadFromFile(ifstream& file) {
	int x, y, width, height;
	file >> x >> y >> width >> height;
	coord = Vector2D(x, y);
	w = width;
	h = height;
}
void ArkanoidObject::saveToFile(ofstream& file) {
	file << (int)coord.getX() << " ";
	file << (int)coord.getY() << " ";
	file << (int)w << " ";
	file << (int)h << endl;
}