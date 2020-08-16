#include "curve.hpp"
#include "soleq.h"
#include <vector>
class Parabola : public Curve{
/*	private:
	 	
		double koefX0(Point p1, Point p2){
			return p2.y + 2 * p2.x * p1.y - p1.y;
		}
		
		double koefY0(Point p1, Point p2){
			return p2.x * p2.x - p1.x * p1.x;
		}
		
		double koefT(Point p1, Point p2){
			return 2 * (p1.x - p2.x);
		}
		
		double koefD(Point p1, Point p2){
			return p1.x * p1.x * p2.y - p2.x * p2.x * p1.y;
		}
		*/
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
		/*	for(int i = 0, j = 1; i < p.size(); i++, j++){
				if(j == p.size()) j = 0;
				if(vertical){
					temp.push_back(this->koefX0(p[i].x, p[j]));
					temp.push_back(this->koefY0(p[i], p[j]));
				}
				else{
					temp.push_back(this->koefY0(p[i], p[j]));
					temp.push_back(this->koefX0(p[i], p[j]));
				}
				temp.push_back(this->koefT(p[i], p[j]));
				temp.push_back(this->koefD(p[i], p[j]));
				equation.push_back(temp);
				temp.clear();
			}*/
			for(int i = 0, j = 1; i < p.size(); i++, j++){
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
			std::cout <<"test\n"; 
			bool isOneEq = true;
			for (int i = 0; i < a.size(); i++){
				for(int j = 0; j <a[i].size(); j++){
					if(a[i][j] != 0 && j != a[i].size() - 1) isOneEq = false;
				}
			}
			double a1,b1,c1;
			a1 = a[0][a[0].size()-1];
			b1 = a[1][a[0].size() - 1];
			c1 = a[2][a[0].size()-1];
			std::cout <<"test\n"; 
			if(!isOneEq){
				throw std::invalid_argument("\nReshenie ne odno\n");
			}
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
	//		vctr.push_back(Point(x, getY(t)));
	//		vctr.push_back(Point(x + 1, -((x + 1 - x0) * x + (-x0 * x - y0 * y + x0 * x0 + y0 * y0 - r * r))/ y0 + y));
			return vctr;
		}
};