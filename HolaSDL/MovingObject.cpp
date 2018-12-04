#include"MovingObject.h"

using namespace std;

MovingObject::~MovingObject() {

}
void MovingObject::loadFromFile(ifstream& file) {
	int vx, vy;
	file >> vx >> vy;
	velocidad = Vector2D(vx, vy);
	ArkanoidObject::loadFromFile(file);
}

void MovingObject::saveToFile(ofstream& file) {
	file << velocidad.getX() << " ";
	file << velocidad.getY() << " ";
	ArkanoidObject::saveToFile(file);
}
