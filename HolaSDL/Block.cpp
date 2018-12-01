#include "Block.h"
#include "Vector2D.h"
#include"Texture.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

using namespace std;
//Block::Block(uint ancho, uint alto, Vector2D coord, uint color, Texture * textura){}

void Block::render() const { // solo lee no cambia nada
	SDL_Rect destRect;
	destRect.x = coord.getX();
	destRect.y = coord.getY();
	destRect.h = h;
	destRect.w = w;
	uint row, col;
	if (color >= 1 && color <= 3) {
		row = 0;
	}
	else { row = 1; }
	if (color == 1 || color == 4) col = 0;
	else if (color == 2 || color == 5) col = 1;
	else col= 2;
	
	if (color != 0) {
		if (textura != nullptr) {
			textura->renderFrame(destRect, row, col, 0, SDL_FLIP_NONE);
		}
	}
	//void renderFrame(const SDL_Rect& destRect, int row, int col, int angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE) const;
}
void Block::update() {

}