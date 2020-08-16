#include "curve.hpp"
#include "soleq.h"
#include <cmath>
class Circle : public Curve{
	
	double tangentEquation(double x){
		double x1 = getX(t);
		double y1 = getY(t);
		return ((x1  - x0) * x + (-x0 * x - y0 * y1 + x0 * x0 + y0 * y0 - r / 2)) / (y1 - y0); // r * r ?
	}
	
	protected:
		double r;
	
		Circle(){}
		
	public:
		
		Circle(Point p1, Point p2, Point p3){
			setPoint(p1, p2, p3);
			std::vector<std::vector<double>> equation;
			std::vector<double> temp;
			std::vector<Point> p;
			p.push_back(p1);
			p.push_back(p2);
			p.push_back(p3);
			for(int i = 0; i < p.size(); i++){
				temp.push_back(p[i].x );
				temp.push_back(p[i].y);
			//	temp.push_back(-p[i].x * p[i].x -p[i].y * p[i].y + p[j].x * p[j].x + p[j].x * p[j].x);
				temp.push_back(1);
				temp.push_back(p[i].x * p[i].x + p[i].y * p[i].y);
				equation.push_back(temp);
				temp.clear();
			}
		/*	for (int i = 0; i < equation.size(); i++){
				for(int j = 0; j <equation[i].size(); j++){
					std:: cout << equation[i][j] << "\t";
					
				}
				std:: cout << "\n";
			}
			std::cout << "\n\n";*/
			Soleq soleq(equation);
			Soleq::Answer answer = soleq.solve();
			std::vector<std::vector<double>> & a = answer.general_solution;
			bool isOneEq = true;
			for (int i = 0; i < a.size(); i++){
				for(int j = 0; j <a[i].size(); j++){
				//	std:: cout << a[i][j] << "\t";
					if(a[i][j] != 0 && j != a[i].size() - 1) isOneEq = false;
				}
			//	std:: cout << "\n";
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
		
};
