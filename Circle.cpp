#include "circle.hpp"

Circle(Point p1, Point p2, Point p3){
			double ma = (p2.y - p1.y) / (p2.x - p1.x);
			double mb = (p3.y - p2.y) / (p3.x - p2.x);
			
			x0 = ma * mb * (p1.y - p3.y) + mb * (p1.x + p2.x) - ma * (p2.x + p3.y);
			y0 = (x0 - (p1.x - p2.x) / 2) / ma + (p1.y + p2.y) / 2;
			r = sqrt(pow(x0 - p1.x, 2) + pow(y0 - p1.y, 2));
			
		}
