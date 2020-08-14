#include "circle.h"
#include <cmart>
#include <vector>
class Ellips : Circle {
	protected:
		
		double a;
		double b;
	
	public:
		
		double getX(double t){
			return a * r * cos(t) + x0;
		}
		
		double getY(double t){
			return b * r * sin(t) + y0;
		}
		
		vector<Point > tangentVector(double t){
			vector<Point > vctr;
			vctr.push_back(Point(getX(t), getY(t)));
			vctr.push_back(Point(getX(t) + 1, (-(b * cos(t) / a) * (getX(t) + 1) + r * b) / sin(t)));
			return vctr;
		}
};
