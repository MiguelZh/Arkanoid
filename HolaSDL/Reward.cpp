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
void Reward::render() {
	if (tiempo < velocidadAnim) {
		Frame++;
		tiempo = 0;
		if (Frame == 7) {
			Frame = 0;
		}
		renderFrame(tp, Frame);
	}
}
void Reward::update() {

}
void Reward::Tipo(uint type) {
	switch (type)
	{
	case 0: // nuevo nv
		break;
	case 1: // alargar
		break;
	case 3: // acortar
		break;
	case 4: // vida++
		break;
	}
}