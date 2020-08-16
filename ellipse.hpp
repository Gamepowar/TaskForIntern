#include "circle.hpp"
#include <cmath>
#include <vector>
class myEllipse : public Circle {
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
		
		myEllipse(Point p1, Point p2, Point p3){
			std::cout << "Choose how you want to build the ellipse:\n1) Three points with center at point (0, 0);\n2) By three points with an offset (you will need to enter 2 more points);\n";
			int choice;
			std::cin >> choice;
			if(choice == 1){
				
				std:: cout << "test\n";
				x0 = 0;
				y0 = 0;
				std::vector<std::vector<double>> equation;
				std::vector<double> temp;
				std::vector<Point> p;
				p.push_back(p1);
				p.push_back(p2);
				p.push_back(p3);
				for(int i = 0; i < p.size() - 1; i++){
					temp.push_back((p[i].x) * (p[i].x));
					temp.push_back((p[i].y) * (p[i].y));
					temp.push_back(1);
					equation.push_back(temp);
					temp.clear();
				}
				for (int i = 0; i < equation.size(); i++){
					for(int j = 0; j <equation[i].size(); j++){
						std::cout << equation[i][j] << "\t";
					}
					std::cout << "\n";
				}
				Soleq soleq(equation);
				Soleq::Answer answer = soleq.solve();
				std::vector<std::vector<double>> & a = answer.general_solution;
				bool isOneEq = true;
				for (int i = 0; i < a.size(); i++){
					for(int j = 0; j <a[i].size(); j++){
						if(a[i][j] != 0 && j != a[i].size() - 1) isOneEq = false;
						std::cout << a[i][j] << "\t";
					}
					std::cout << "\n";
				}
				if(!isOneEq){
					throw std::invalid_argument("\nWrong data\n");
				}
				
				std:: cout << "test\n";
				this->a = 1/sqrt(a[0][a[0].size()-1]);
				this->b = 1/sqrt(a[1][a[0].size() - 1]);
				this->r = 1;
				std::cout << "a = " << this->a << ", b = " << this->b << std::endl;
			}
			else if(choice == 2){
				std::vector<std::vector<double>> equation;
				std::vector<double> temp;
				std::vector<Point> p;
				p.push_back(p1);
				p.push_back(p2);
				p.push_back(p3);
				for(int i = 0; i < p.size(); i++){
					temp.push_back(1);
					temp.push_back((p[i].x));
					temp.push_back((p[i].y));
					temp.push_back((p[i].x) * (p[i].x));
					temp.push_back((p[i].y) * (p[i].y));
					temp.push_back(0);
					equation.push_back(temp);
					temp.clear();
				}
				temp = std::vector<double> (6,0);
				equation.push_back(temp);
				equation.push_back(temp);
				
				for (int i = 0; i < equation.size(); i++){
					for(int j = 0; j <equation[i].size(); j++){
						std::cout << equation[i][j] << "\t";
					}
					std::cout << "\n";
				}
				std::cout << "\n\n";
				Soleq soleq(equation);
				Soleq::Answer answer = soleq.solve();
				std::vector<std::vector<double>> & a = answer.general_solution;
				for (int i = 0; i < a.size(); i++){
					for(int j = 0; j <a[i].size(); j++){
					//	if(a[i][j] != 0 && j != a[i].size() - 1) isOneEq = false;
						std::cout << a[i][j] << "\t";
					}
					std::cout << "\n";
				}
				std::cout << "Enter variable a (from ellipse equation) : ";
				std::cin >> this->a;
				std::cout << "Enter variable b (from ellipse equation) : ";
				std::cin >> this->b;
				double A,B,C,D,E;
				std::vector<double> res;
				D = 1/(this->a * this->a);
				E = 1 / (this->b * this->b);
				for(int i = 0; i < a.size(); i++){
					res.push_back(a[i][3] * D + a[i][4] * E);
				}
				A = res[0];
				B = res[1];
				C = res[2];
				if(!(D * E > 0 && D * E * A - B * B * E - D * C * C != 0)){
					throw std::invalid_argument("\nWrong data\n");
				}
				x0 = - this->a * this->a * B / 2; 
				y0 = - b * b * C / 2;
				r = sqrt((x0 * x0) / (this->a * this->a) + (y0 * y0) / ( b * b) - A);
				
				
				std::cout << "a = " << this->a << ", b = " << this->b << std::endl;
			}
		}
};
