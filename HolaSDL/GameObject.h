#pragma once
#include <iostream>
#include "checkML.h"


class GameObject {
	//~GameObject(){}
	virtual void render() ;
	virtual void update() ;
	virtual void handleEvent() ;
};