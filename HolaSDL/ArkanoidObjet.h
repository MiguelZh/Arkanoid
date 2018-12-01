#pragma once
#include"GameObjet.h"
#include <iostream>
#include "Vector2D.h"
#include "math.h"
class ArkanoidObjet: public GameObjet
{
public:
	ArkanoidObjet();
	~ArkanoidObjet();
	virtual void loadFromFile(string filename){}
	virtual void saveToFile(){}
	SDL_Rect * getRect(){}
protected:
	uint w, h; 
	Vector2D coord;
	Texture * textura = nullptr;
private:

};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}
