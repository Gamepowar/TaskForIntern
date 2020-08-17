#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "curve.hpp"
#include "soleq.hpp"
#include <cmath>
class Circle : public Curve{
protected:
	double r;

	Circle(){}
	
public:
	
	Circle(const Point & p1, const Point & p2, const Point & p3);
	
	double getX(double t) const;
	
	double getY(double t) const;
	
	double getR() const;
	
	void showInfo() const;
	
	bool isClosed() const;
	
	std::vector<Point> tangentVector(double t) const;
};

#endif

