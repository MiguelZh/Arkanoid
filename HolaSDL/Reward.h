#pragma once
#include "MovingObject.h"
class Reward :public MovingObject {
protected:

public:
	Reward(uint width, uint height, Vector2D coord, Texture * t, Vector2D vel):
		MovingObject(width,height,coord,t,vel){}
	void render();
	void update(); // debatir un update que llame a otro update del padre para que sea mas eficiente(posterior)
	bool collides(const SDL_Rect destRect); // implementar collision con el paddle
};