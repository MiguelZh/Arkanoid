#pragma once
#include "MovingObject.h"
class Reward :public MovingObject {
protected:

public:
	Reward(uint width, uint height, Vector2D coord, Texture * t, Vector2D vel):
		MovingObject(width,height,coord,t,vel){}
	void update();
};