#pragma once
#include "ArkanoidObject.h"
class MovingObject : public ArkanoidObject {
protected:
	Vector2D velocidad;
public:
	MovingObject(){}
	MovingObject(uint width, uint height, Vector2D coord, Texture * t,Vector2D vel):
		ArkanoidObject(width,height,coord,t),velocidad(vel){}
	~MovingObject(){}

	void loadFromFile() {}
	void saveToFile(){} // guardan y cargan velocidad
};