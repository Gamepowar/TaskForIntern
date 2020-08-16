#include "curve.hpp"
//#include "soleq.h"
#include <vector>
class Parabola : public Curve{
	protected:
		
		bool vertical;
		double p;
		
	public:
		
		Parabola(Point p1, Point p2, Point p3, bool vertical = true){
			setPoint(p1, p2, p3);
			
			this->vertical = vertical; 
			std::vector<std::vector<double>> equation;
			std::vector<double> temp;
			std::vector<Point> p;
			p.push_back(p1);
			p.push_back(p2);
			p.push_back(p3);
			
			for(int i = 0; i < p.size(); i++){
				if(vertical){
					temp.push_back(p[i].x * p[i].x);
					temp.push_back(p[i].x);
					temp.push_back(1);
					temp.push_back(p[i].y);
				}
				else{
					temp.push_back(p[i].y * p[i].y);
					temp.push_back(p[i].y);
					temp.push_back(1);
					temp.push_back(p[i].x);
				}
				equation.push_back(temp);
				temp.clear();
			}
			Soleq soleq(equation);
			Soleq::Answer answer = soleq.solve();
			std::vector<std::vector<double>> & a = answer.general_solution;
			bool isOneEq = true;
			for (int i = 0; i < a.size(); i++){
				for(int j = 0; j <a[i].size(); j++){
					if(a[i][j] != 0 && j != a[i].size() - 1) isOneEq = false;
				}
			}
			if(!isOneEq){
				throw std::invalid_argument("\nWrong data\n");
			}
			double a1,b1,c1;
			a1 = a[0][a[0].size()-1];
			b1 = a[1][a[0].size() - 1];
			c1 = a[2][a[0].size()-1];
			if(vertical){
			/*	x0 = -a[1][a[0].size() - 1] /(2 * a[0][a[0].size()-1]);
				y0 = (a[1][a[0].size() - 1] * a[1][a[0].size() - 1] - 4 * a[0][a[0].size()-1]) - a[2][a[0].size()-1];*/
				x0 = -b1 / (2 * a1);
				y0 = -(b1*b1 - 4 * a1 * c1) / (4 * a1); 
			}
			else{
				y0 = -b1 / (2 * a1);
				x0 = -(b1*b1 - 4 * a1 * c1) / (4 * a1); ;
			}
			this->p = 1/ (2 * a1);
			
			
		}
		
		double getP(){
			return p;
		}
		
		double getX(double t){
			if (vertical)	return t + x0;
			else	return (t * t )/ (2 * p) + x0;
		}
		
		double getY(double t){
			if(vertical)	return t * t / (2 * p) + y0;
			else 	return t + y0;
		}
		
		virtual bool isClosed(){
			return false;
		}
		
		std::vector<Point > tangentVector(double t){
			std::vector<Point > vctr;
			double x = getX(t);
			double y = getY(t);
			vctr.push_back(Point(x, y));
			vctr.push_back(Point(x + 1, (x / p - x0 / p)(x + 1) + x0 * x0(2 * p)));
			return vctr;
		}
};
