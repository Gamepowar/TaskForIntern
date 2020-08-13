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
	private:
		
	
	public: 
		Curve(){}
	
	/*	Curve(double a, double b, double c){
			this.a = a;
			this.b = b;
			this.c = c;
		}
		*/
		Curve(double x1, double y1, double x2, double y2, double x3, double y3) = 0;
		
//		virtual void parametricForm() = 0;
		
	//	virtual Point 
		virtual double getX(double t) = 0;
		
		virtual double getY(double t) = 0;
		
		virtual bool isClosed() = 0;
		
		virtual Vector tangentVector(double t) = 0;
		
		
		
};
