#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>

class Point{
public:
	double x;
	double y;
	
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	
	void show() const;

};

#endif
