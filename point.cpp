#include "point.hpp"

void Point::show() const {
	std::cout << "x = " << x << ", y = " << y << std::endl; 
}

void Point::setCoordinates (double x, double y){
	this->x = x;
	this->y = y;
}
void Point::swap(Point& p){
	Point temp(p.x, p.y);
	p.setCoordinates(this->x, this->y);
	this->setCoordinates(temp.x, temp.y);
}
