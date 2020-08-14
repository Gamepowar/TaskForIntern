#include "Curve.h"
#include <cmart>
#include <vector>
class Ellips : Curve {
	
	
	public:
		
		double getX(double t){
			return a * r * cos(t) + x0;
		}
		
		double getY(double t){
			return b * r * sin(t) + y0;
		}
		
		bool isClosed(){
			return true;
		}
		
		vector<double > tangentVector(double t){
			vector<double > straight;
			straight.push_back(-(cos(t) * b )/ (sin(t) * a));
			straight.push_back(r * b / sin(t));
			return straight;
		}
};
