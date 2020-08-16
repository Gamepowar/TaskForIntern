#include "circle.hpp"
#include <cmath>
#include <vector>
class Ellipse : public Circle {
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
		
		std::vector<Point > tangentVector(double t){
			std::vector<Point> vctr;
			double x = getX(t);
			vctr.push_back(Point(x, getY(t)));
			vctr.push_back(Point(x + 1, (-(b * cos(t) / a) * (x + 1) + r * b) / sin(t)));
			return vctr;
		}
		
		Ellipse(Point p1, Point p2, Point p3){
			std::cout << "Choose how you want to build the ellipse:\n1) Three points with center at point (0, 0);\n2) By three points with an offset (you will need to enter 2 more points);\n";
			int choice;
			std::cin >> choice;
			if(choice == 1){
				x0 = 0;
				y0 = 0;
				std::vector<std::vector<double>> equation;
				std::vector<double> temp;
				std::vector<Point> p;
				p.push_back(p1);
				p.push_back(p2);
				p.push_back(p3);
				for(int i = 0; i < p.size(); i++){
					temp.push_back((p[i].x + x0) * (p[i].x + x0));
					temp.push_back((p[i].y + y0) * (p[i].y + y0));
					temp.push_back(-1);
					temp.push_back(0);
					equation.push_back(temp);
					temp.clear();
				}
				
			} 
		}
};