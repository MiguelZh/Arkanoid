#pragma once
#include "ArkanoidObject.h"
#include "checkML.h"

class MovingObject : public ArkanoidObject {
protected:
	Vector2D velocidad;
public:
	MovingObject(){}
	MovingObject(uint width, uint height, Vector2D coord, Texture * t,Vector2D vel):
		ArkanoidObject(width,height,coord,t),velocidad(vel){}
	virtual ~MovingObject();

	void loadFromFile(ifstream& file);
	void saveToFile(ofstream& file); // guardan y cargan velocidad
};