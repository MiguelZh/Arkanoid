#pragma once
#include"GameObject.h"
#include <iostream>
#include "Vector2D.h"
#include "math.h"
#include <fstream>
#include "checkML.h"
class ArkanoidObject: public GameObject
{
public:
	ArkanoidObject(){}
	ArkanoidObject(uint width,uint height, Vector2D coord , Texture * t):
		w(width),h(height),coord(coord),textura(t){}
	virtual ~ArkanoidObject();
	virtual void loadFromFile(ifstream& file);
	virtual void saveToFile(ofstream & file);
	virtual void render();
	virtual void update() {};
	virtual void handleEvent() {};
	void renderFrame(uint row, uint col);
	SDL_Rect getRect();
	uint getW() { return w; }
	void setW(uint ancho) { w = ancho; }
	uint getH() { return h; }
	uint getX() { return coord.getX(); }
	uint getY() { return coord.getY(); }
protected:
	uint w = 0, h = 0; 
	Vector2D coord;
	Texture * textura = nullptr;
private:

};

