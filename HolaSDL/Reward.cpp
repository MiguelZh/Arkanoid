#include "Reward.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
 
void Reward::render() {
	if (SDL_GetTicks() > velocidadAnim+tiempo) {
		Frame++;
		tiempo = SDL_GetTicks();
		if (Frame == 7) {
			Frame = 0;
		}
		renderFrame(rewardT, Frame);
	}
}
void Reward::update() {
	if (coord.getY() > 600) { 
	game->destruyeReward();
	}
	if (SDL_HasIntersection(&paddle->getRect(), &getRect())) { //comenta esto si no quieres tener el error
		TipodeRecompensa();
	}
	coord = coord + velocidad;
}	
void Reward::TipodeRecompensa() {
	paddle->reset();
	switch (rewardT)
	{
	case 0: // nuevo nv
		game->rewardMasNivel();
		break;
	case 1: // alargar
		paddle->alargar();
		break;
	case 3: // acortar
		paddle->acortar();
		break;
	case 4: // vida++
		bola->masVida();
		break;
	}
}
