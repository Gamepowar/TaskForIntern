#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "curve.hpp"
#include "soleq.hpp"
#include <cmath>
class Circle : public Curve{
protected:
	double r;

	Circle(){}
	
	/*bool isPerpendicular(Point p1, Point p2, Point p3){
	
			// Check the given point are perpendicular to x or y axis 
		double yDelta_a = p2.y - p1.y;
		double xDelta_a = p2.x - p1.x;
		double yDelta_b = p3.y - p2.y;
		double xDelta_b = p3.x - p2.x;
		double const eps  =0.0001;
			// checking whether the line of the two pts are vertical
		if (fabs(xDelta_a) <= eps && fabs(yDelta_b) <= eps){
			return false;
		}
			if (fabs(yDelta_a) <= eps){
			return true;
		}
		else if (fabs(yDelta_b) <= eps){
			return true;
		}
		else if (fabs(xDelta_a)<= eps){
			return true;
		}
		else if (fabs(xDelta_b)<= eps){
			return true;
		}
		else return false ;
	}*/
	
public:
	
	Circle(const Point & p1, const Point & p2, const Point & p3);
	
	double getX(double t) const;
	
	double getY(double t) const;
	
	double getR() const;
	
	bool isClosed() const;
	
	std::vector<Point> tangentVector(double t) const;
};

#endif

