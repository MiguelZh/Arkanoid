#pragma once
#include"GameObject.h"
#include <iostream>
#include "Vector2D.h"
#include "math.h"
#include <fstream>
class ArkanoidObject: public GameObject
{
public:
	ArkanoidObject(){}
	ArkanoidObject(uint width,uint height, Vector2D coord , Texture * t):
		w(width),h(height),coord(coord),textura(t){}
	~ArkanoidObject();
	virtual void loadFromFile(ifstream& file);
	virtual void saveToFile(ofstream & file);
	void render();
	void renderFrame(uint row, uint col);
	SDL_Rect getRect();
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

