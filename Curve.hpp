#ifndef CURVE_HPP
#define CURVE_HPP

#include "point.hpp"
#include <vector>
#include <cmath>
#include <stdexcept>

class Curve{
	
protected:
	double x0; // x-offset 
	double y0; // y-offset
	
	Point p1;
	Point p2;
	Point p3;
	
	void setPoint(const Point & p1, const Point & p2, const Point & p3);
		
public: 

	double getX0() const;
	
	double getY0() const;
	
	virtual double getX(double t) const = 0;
	
	virtual double getY(double t) const = 0;
	
	virtual bool isClosed() const = 0;
	
	virtual void showInfo() const = 0;
	
	virtual std::vector<Point> tangentVector(double t) const = 0;
	
	virtual ~Curve() {}		
		
};

#endif
