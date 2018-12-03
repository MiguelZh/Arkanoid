#pragma once
#include "MovingObject.h"
#include <vector>
class Reward :public MovingObject {
protected:
	uint tp; uint velocidadAnim = 20; uint Frame = 0;  uint tiempo = 0;
public:
	Reward(uint width, uint height, Vector2D coord, Texture * t, Vector2D vel,uint type):
		MovingObject(width,height,coord,t,vel),tp(type){}
	void render();
	void update(); // debatir un update que llame a otro update del padre para que sea mas eficiente(posterior)
	bool collides(const SDL_Rect destRect); // implementar collision con el paddle
	void Tipo(uint type);
	uint getTicks() { return tiempo = SDL_GetTicks(); }
};