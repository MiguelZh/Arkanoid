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
	/*if (coord.getY() > 600) { 
		game->
	}*/
	coord = coord + velocidad;
}
void Reward::Tipo(uint type) {
	paddle->reset();
	switch (type)
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
bool Reward::collides(SDL_Rect PaddleRect) {
	if (SDL_HasIntersection(&PaddleRect, &getRect())) {
		Tipo(rewardT);
		return true;
	}
	return false;
}