#pragma once
#include "ArkanoidObject.h"
class MovingObject : public ArkanoidObject {
protected:
	Vector2D velocidad;
public:
	MovingObject(uint width, uint height, Vector2D coord, Texture * t,Vector2D vel):
		ArkanoidObject(width,height,coord,t),velocidad(vel){}
	void update();
	virtual void loadFromFile() {}
	virtual void saveToFile(){} // guardan y cargan velocidad
};