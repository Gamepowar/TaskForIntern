#include "point.hpp"
#include <vector>
/*
struct Point{
	double x;
	double y;		
};*/


class Curve{
	protected:
		double t;
		double x0;
		double y0;
		
	public: 
	
		Curve(Point p1, Point p2, Point p3);
		
		virtual double getX(double t) = 0;
		
		virtual double getY(double t) = 0;
		
		virtual bool isClosed() = 0;
		
		virtual std::vector<Point > tangentVector(double t) = 0;
		
		virtual ~Curve() = 0;
		
};
