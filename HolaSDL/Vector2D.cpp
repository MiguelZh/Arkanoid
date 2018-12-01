#include "Vector2D.h"
#include "math.h"
#include <iostream>

Vector2D::Vector2D(): x(), y(){}

Vector2D::Vector2D(double x, double y): x(x), y(y){}

double Vector2D::getX() const { return x; }

double Vector2D::getY() const { return y; }

void Vector2D::normalize() {
	double mag = sqrt(pow(x, 2) + pow(y, 2));
	if (mag > 0.0) {
		x = x / mag;
		y = y / mag;
	}
}

Vector2D Vector2D::operator+(const Vector2D& v) const {
	Vector2D r;
	r.x = this->x + v.x;
	r.y = this->y + v.y;
	return r;
}
Vector2D Vector2D::operator-(const Vector2D& v) const {
	Vector2D r;
	r.x = this->x - v.x;
	r.y = this->y - v.y;
	return r;
}

Vector2D Vector2D::operator*(double d) const {
	Vector2D r;
	r.x = x * d;
	r.y = y * d;
	return r;
}

double Vector2D::operator*(const Vector2D& d) const {
	return d.x*x + d.y*y;
}

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
	os << "(" << v.x << "," << v.y << ")";
	return os;
}

int main() {
	Vector2D a(1, 1);
	Vector2D b = Vector2D(2, 2);
	a = a * 2;
	Vector2D c = a + b;
	c.normalize();
	cout << "El prod. escalar de "
		<< a << " y " << b << " es "
		<< a * b << endl;

	system("pause");
	return 0;
};