#include "Point.hpp"

struct Point{
	double x;
	double y;		
};

struct Vector{
	double a;
	double b;
};

class Curve{
	protected:
		double t;
	
	public: 
	
		Curve(Point p1, Point p2, Point p3) = 0;
		
		virtual double getX(double t) = 0;
		
		virtual double getY(double t) = 0;
		
		virtual bool isClosed() = 0;
		
		virtual Vector tangentVector(double t) = 0;
		
		
		
};
