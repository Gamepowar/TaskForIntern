#include "Point.hpp"

struct Point{
	double x;
	double y;		
};


class Curve{
	protected:
		double t;
		double x0;
		double y0;
		
	public: 
	
		Curve(Point p1, Point p2, Point p3) = 0;
		
		virtual double getX(double t) = 0;
		
		virtual double getY(double t) = 0;
		
		virtual bool isClosed() = 0;
		
		virtual vector<double > tangentVector(double t) = 0;
		
		
		
};
