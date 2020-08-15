#include "curve.hpp"
#include <vector>
#include <cmath>
class Circle : public Curve{
	protected:
		double r;
	
		Circle(){}
	public:
	
		Circle(Point p1, Point p2, Point p3){
			double ma = (p2.y - p1.y) / (p2.x - p1.x);
			double mb = (p3.y - p2.y) / (p3.x - p2.x);
			
			x0 = ma * mb * (p1.y - p3.y) + mb * (p1.x + p2.x) - ma * (p2.x + p3.y);
			y0 = (x0 - (p1.x - p2.x) / 2) / ma + (p1.y + p2.y) / 2;
			r = sqrt(pow(x0 - p1.x, 2) + pow(y0 - p1.y, 2));
			
		}
		
		double getX(double t){
			return r * cos(t) + x0;
		}
		
		double getY(double t){
			return r * sin(t) + y0;
		}
		
		virtual bool isClosed(){
			return true;
		}
		
		std::vector<Point> tangentVector(double t){
			std::vector<Point> vctr;
			double x = getX(t);
			double y = getY(t);
			vctr.push_back(Point(x, getY(t)));
			vctr.push_back(Point(x + 1, -((x + 1 - x0) * x + (-x0 * x - y0 * y + x0 * x0 + y0 * y0 - r * r))/ y0 + y));
			return vctr;
		}
};
