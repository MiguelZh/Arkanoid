#pragma once

#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
#include "Texture.h"
#include "Vector2D.h"
#include "math.h"
#include <iostream>
#include "ArkanoidObject.h"
using namespace std;

class Block : public ArkanoidObject{
private:
	uint row = 0, col = 0;
	uint color = 0; 
public:
	Block(uint color,uint ancho, uint alto, Vector2D coord, Texture * textura, uint row, uint col):
		color(color),ArkanoidObject(ancho,alto,coord,textura), row(row),col(col){}
	~Block() {}
	void render() const;
	double getX() { return coord.getX(); }
	double getY() { return coord.getY(); }
	uint getRow() { return row; }
	uint getCol() { return col; }
	void update();
	void handleEvent(SDL_Event E);

	//void renderFrame(const SDL_Rect& destRect, int row, int col, int angle = 0, SDL_RendererFlip flip = SDL_FLIP_NONE) const;
};
