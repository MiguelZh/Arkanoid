#include "Reward.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
 
bool Reward::collides(const SDL_Rect destRect) {

	if (SDL_HasIntersection(&destRect,&getRect())) {
		// si detecta colision... , llama los metodos o activarian los premios por colisionar con el paddle
		return true;
	}
	else return false;
}