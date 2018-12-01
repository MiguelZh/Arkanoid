#include "Texture.h"
#include "Vector2D.h"
#include "Wall.h"
#include "SDL.h"
#include "SDL_image.h"

using namespace std;

// Paddle::Paddle(Texture * textura, Vector2D coord, int ancho, int alto){}

bool Wall::collides(const SDL_Rect destRect, Vector2D &collVector) { // al declarar los muros en game, se llamaran asi 
	if (SDL_HasIntersection(&destRect, &getRect())) {
		if (muro == "Right") {
			collVector = Vector2D(-1, 0);
		}
		if (muro == "Left") {
			collVector = Vector2D(1, 0);
		}
		if (muro =="Top") {
			collVector = Vector2D(0, 1);
		}
		return true;
	}
	return false;
}




