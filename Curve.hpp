#ifndef CURVE_HPP
#define CURVE_HPP

#include "point.hpp"
#include <vector>
#include <cmath>
#include <stdexcept>
/*
struct Point{
	double x;
	double y;		
};*/


class Curve{
	
	protected:
		double x0;
		double y0;
		
		Point p1;
		Point p2;
		Point p3;
		
		
		
		void setPoint(Point p1, Point p2, Point p3){
		
			double const eps  =0.0001;
			if (fabs(p3.x * (p2.y - p1.y) - p3.y * (p2.x - p1.x) - (p1.x * p2.y - p2.x * p1.y)) < eps){
				throw std::invalid_argument("\n3 dots cannot lie on the same line\n");
			}
			this->p1 = p1;
			this->p2 = p2;
			this->p3 = p3;
		}
		
	public: 
	
		double getX0() {
			return x0;
		}
		
		double getY0(){
			return y0;
		}
		
		virtual double getX(double t) = 0;
		
		virtual double getY(double t) = 0;
		
		virtual bool isClosed() = 0;
		
		virtual std::vector<Point> tangentVector(double t) = 0;
		
		virtual ~Curve() {}
		
		
};

#endif
