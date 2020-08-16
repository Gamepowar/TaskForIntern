#include "curve.hpp"
//#include "soleq.h"
#include <vector>
class Parabola : public Curve{
	
	double tangentEquation(double x){
		double x1 = getX(t);
		double y1 = getY(t);
		return (x1 / p - x0 / p) * x + y1 + x1 * x1 * (2 * p);
	}
	
	protected:
		
		bool vertical;
		double p;
		
	public:
		
		Parabola(Point p1, Point p2, Point p3, bool vertical = true){
			setPoint(p1, p2, p3);
			
			this->vertical = vertical; 
			std::vector<std::vector<double>> equation;
		//	std::vector<double> temp;
			std::vector<Point> points({p1, p2, p3});
		/*	p.push_back(p1);
			p.push_back(p2);
			p.push_back(p3);*/
			
			for(int i = 0; i < points.size(); i++){
				if(vertical){
				/*	temp.push_back(p[i].x * p[i].x);
					temp.push_back(p[i].x);
					temp.push_back(1);
					temp.push_back(p[i].y);*/
					equation.push_back(std::vector<double>({points[i].x * points[i].x, points[i].x, 1, points[i].y}));
				}
				else{
				/*	temp.push_back(p[i].y * p[i].y);
					temp.push_back(p[i].y);
					temp.push_back(1);
					temp.push_back(p[i].x);*/
					equation.push_back(std::vector<double>({points[i].y * points[i].y, points[i].y, 1, points[i].x}));
				}
			/*	equation.push_back(temp);
				temp.clear();*/
			}
			Soleq soleq(equation);
			Soleq::Answer answer = soleq.solve();
			std::vector<std::vector<double>> & arr = answer.general_solution;
			bool isOneEq = true;
			for (int i = 0; i < arr.size(); i++){
				for(int j = 0; j <arr[i].size(); j++){
					if(arr[i][j] != 0 && j != arr[i].size() - 1) isOneEq = false;
				}
			}
			if(!isOneEq){
				throw std::invalid_argument("\nWrong data\n");
			}
			double a, b, c;
			a = arr[0][arr[0].size() - 1];
			b = arr[1][arr[0].size() - 1];
			c = arr[2][arr[0].size() - 1];
			if(vertical){
				x0 = -b / (2 * a);
				y0 = -(b * b - 4 * a * c) / (4 * a); 
			}
			else{
				y0 = -b / (2 * a);
				x0 = -(b * b - 4 * a * c) / (4 * a); ;
			}
			p = 1/ (2 * a);
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
		
};
