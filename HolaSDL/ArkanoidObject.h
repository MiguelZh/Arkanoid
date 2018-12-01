#pragma once
#include"GameObject.h"
#include <iostream>
#include "Vector2D.h"
#include "math.h"
class ArkanoidObject: public GameObject
{
public:
	ArkanoidObject(uint width,uint height, Vector2D coord , Texture * t):
		w(width),h(height),coord(coord),textura(t){}
	~ArkanoidObject();
	virtual void loadFromFile(string filename){}
	virtual void saveToFile(){}
	void render();
	SDL_Rect  getRect(){}
	uint getW() { return w; }
	uint getH() { return h; }
	uint getX() { return coord.getX(); }
	uint getY() { return coord.getY(); }
protected:
	uint w = 0, h = 0; 
	Vector2D coord;
	Texture * textura = nullptr;
private:

};

