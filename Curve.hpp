#ifndef CURVE_HPP
#define CURVE_HPP

#include "point.hpp"
#include <vector>
/*
struct Point{
	double x;
	double y;		
};*/


class Curve{
	protected:
		double x0;
		double y0;
		
	public: 
	
		
		virtual double getX(double t) = 0;
		
		virtual double getY(double t) = 0;
		
		virtual bool isClosed() = 0;
		
		virtual std::vector<Point> tangentVector(double t) = 0;
		
		virtual ~Curve() {}
		
		
};

#endif
