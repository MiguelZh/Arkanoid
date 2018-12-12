#pragma once
#include "MovingObject.h"
#include <vector>
#include "Game.h"
#include "Paddle.h"
#include "Ball.h"
#include "checkML.h"

class Game;
class Reward :public MovingObject {
protected:
	uint rewardT; float velocidadAnim =0.02; uint Frame = 0;  uint tiempo = 0; Game * game; Paddle * paddle; Ball * bola;
public:
	Reward(uint width, uint height, Vector2D coord, Texture * t, Vector2D vel,uint type, Game *game):
		MovingObject(width,height,coord,t,vel), rewardT(type), game(game){}
	~Reward() { game = nullptr; }
	void render();
	void update(); // debatir un update que llame a otro update del padre para que sea mas eficiente(posterior)
	void TipodeRecompensa();
};