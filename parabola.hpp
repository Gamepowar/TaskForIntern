#include "curve.hpp"

class Parabola : public Curve{
	protected:
		
		double p;
		bool vertical;
		
		
		
	public:
		
		
		
		double getX(double t){
			if (vertical)	return t;
			else	return t * t / (2 * p);
		}
		
		double getY(double t){
			if(vertical)	return t * t / (2 * p);
			else 	return t;
		}
		
		virtual bool isClosed(){
			return false;
		}
		
		std::vector<Point > tangentVector(double t){
			vector<Point > vctr;
			double x = getX(t);
			double y = getY(t);
	//		vctr.push_back(Point(x, getY(t)));
	//		vctr.push_back(Point(x + 1, -((x + 1 - x0) * x + (-x0 * x - y0 * y + x0 * x0 + y0 * y0 - r * r))/ y0 + y));
			return vctr;
		}
};
