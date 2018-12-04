#pragma once


#include "Block.h"
#include "Texture.h"
#include <iostream>
#include "ArkanoidObject.h"
#include "Game.h"
#include "checkML.h"

using namespace std;
class BlocksMap:public ArkanoidObject{
private:
	Block *** blocks = nullptr;
	uint numBloques, puntos = 0, puntosAnt = 0;
public:
	BlocksMap( uint w, uint h, Texture * t):
		ArkanoidObject(w, h, {0,0}, t) {}
	~BlocksMap();
	void LeerFichero(string filename);
	void render() const;
	bool detectCollision(const SDL_Rect destRect, Vector2D &collVector, const Vector2D &vel,Game * g);
	Block* BlocksMap::collides(const SDL_Rect& ballRect, const Vector2D& ballVel, Vector2D& collVector);
	Block* BlocksMap::blockAt(const Vector2D& p);
	void ballHitBlock(Block * bloque);
	bool pasoNivel();
	void puntuacion();
	
};

