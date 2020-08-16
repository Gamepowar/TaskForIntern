#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "circle.hpp"
#include <cmath>
#include <vector>

class myEllipse : public Circle {
protected:
		
	double a;
	double b;

public:
	
	double getX(double t) const;
	
	double getY(double t) const;
	
	std::vector<Point> tangentVector(double t) const;
	
	bool isClosed() const;
	
	myEllipse(const Point & p1, const Point & p2, const Point & p3);
};

#endif
