#include "curve.hpp"
#include "soleq.h"
#include <cmath>
class Circle : public Curve{
	protected:
		double r;
	
		Circle(){}
		
		bool isPerpendicular(Point p1, Point p2, Point p3){
		
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
		}
		
	public:
		
		Circle(Point p1, Point p2, Point p3){
			setPoint(p1, p2, p3);
		/*	
			if (!this->isPerpendicular(p1, p2, p3) );	
			else if (!this->isPerpendicular(p1, p3, p2) ){
				p2.swap(p3);	
			}
			else if (!this->isPerpendicular(p2, p1, p3) ){
				p1.swap(p2);
			}	
			else if (!this->isPerpendicular(p2, p3, p1) ){
				p2.swap(p3); 
				p3.swap(p1);
			}
			else if (!this->isPerpendicular(p3, p2, p1) ){
				p1.swap(p1);
			}	
			else if (!this->isPerpendicular(p3, p1, p2) ){
				p1.swap(p2);
				p1.swap(p3);
			}
			
			double ma = (p2.y - p1.y) / (p2.x - p1.x);
			
			double mb = (p3.y - p2.y) / (p3.x - p2.x);
			
			
			x0 = (ma * mb * (p1.y - p3.y) + mb * (p1.x + p2.x) - ma * (p2.x + p3.x)) / (2 * (mb - ma));
			
			y0 = - ((x0 - (p1.x + p2.x) / 2) / ma) + (p1.y + p2.y) / 2;
			
			r = sqrt(pow(x0 - p1.x, 2) + pow(y0 - p1.y, 2));*/
			std::vector<std::vector<double>> equation;
			std::vector<double> temp;
			std::vector<Point> p;
			p.push_back(p1);
			p.push_back(p2);
			p.push_back(p3);
			for(int i = 0, j = 1; i < p.size(); i++, j++){
				if(j == p.size()) j = 0;
				temp.push_back(p[j].x );
				temp.push_back(p[i].y);
			//	temp.push_back(-p[i].x * p[i].x -p[i].y * p[i].y + p[j].x * p[j].x + p[j].x * p[j].x);
				temp.push_back(1);
				temp.push_back(p[j].x * p[j].x + p[i].y * p[i].y);
				equation.push_back(temp);
				temp.clear();
			}
			for (int i = 0; i < equation.size(); i++){
				for(int j = 0; j <equation[i].size(); j++){
					std:: cout << equation[i][j] << "\t";
					
				}
				std:: cout << "\n";
			}
			std::cout << "\n\n";
			Soleq soleq(equation);
			Soleq::Answer answer = soleq.solve();
			std::vector<std::vector<double>> & a = answer.general_solution;
			bool isOneEq = true;
			for (int i = 0; i < a.size(); i++){
				for(int j = 0; j <a[i].size(); j++){
					std:: cout << a[i][j] << "\t";
					if(a[i][j] != 0 && j != a[i].size() - 1) isOneEq = false;
				}
				std:: cout << "\n";
			}
			if(!isOneEq){
				throw std::invalid_argument("\nWrong data\n");
			}
			x0 = a[0][a[0].size()-1]/2;
			y0 = a[1][a[0].size() - 1]/2 ;
			r = sqrt(pow(x0 - p1.x, 2) + pow(y0 - p1.y, 2));
		}
		
		double getX(double t){
			return r * cos(t) + x0;
		}
		
		double getY(double t){
			return r * sin(t) + y0;
		}
		
		double getR(){
			return r;
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
