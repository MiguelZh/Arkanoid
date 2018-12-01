#pragma once


#include "Block.h"
#include "Texture.h"
#include <iostream>
#include "ArkanoidObject.h"

using namespace std;

class BlocksMap:public ArkanoidObject{
private:
	Block *** blocks = nullptr;
	uint numBloques, puntos = 0, puntosAnt = 0;
public:
	BlocksMap( uint w, uint h,Vector2D coord, Texture * t):
		  ArkanoidObject(w,h,coord,t) {}
	~BlocksMap();
	void LeerFichero(string filename,Texture * texture);
	void render() const;
	Block* BlocksMap::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* BlocksMap::blockAt(const Vector2D& p);
	void ballHitBlock(Block * bloque);
	bool pasoNivel();
	void puntuacion();
	
};

