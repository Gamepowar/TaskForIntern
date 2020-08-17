#include "curve.hpp"

void Curve::setPoint(const Point & p1, const Point & p2, const Point & p3){	
	double const eps  = 0.0001;
	if (fabs(p3.x * (p2.y - p1.y) - p3.y * (p2.x - p1.x) - (p1.x * p2.y - p2.x * p1.y)) < eps){
		throw std::invalid_argument("\n3 dots cannot lie on the same line\n");
	}
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
}

double Curve::getX0() const {
	return x0;
}

double Curve::getY0() const {
	return y0;
}
