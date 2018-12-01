#pragma once
#include <iostream>
#include "checkML.h"
#include "SDL.h" // Windows
#include "SDL_image.h" // Windows
class GameObject {
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void handleEvent(SDL_Event E) = 0;
};