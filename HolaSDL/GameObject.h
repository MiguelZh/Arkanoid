#pragma once
#include <iostream>
#include "checkML.h"


class GameObject {
	//~GameObject(){}
	virtual void render()=0 ;
	virtual void update()=0 ;
};