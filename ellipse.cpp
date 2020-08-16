#include "ellipse.hpp"

double myEllipse::getX(double t) const {
	return a * r * cos(t) + x0;
}
	
double myEllipse::getY(double t) const {
	return b * r * sin(t) + y0;
}
	
std::vector<Point> myEllipse::tangentVector(double t) const {
	const double eps = 0.0001;
	double x = getX(t);
	double shift = 1;
	Point p1(x, getY(t));
	Point p2(x + shift, (-(b * cos(t) / a) * (x + shift) + r * b) / sin(t));
	if (fabs(p2.y - p1.y) < eps) {
		p2.x -= shift;
		p2.y += shift;
	}
	return std::vector<Point>({p1, p2});
}
	
myEllipse::myEllipse(const Point & p1, const Point & p2, const Point & p3){
	try {
		setPoint(p1, p2, p3);
	}
	catch (std::exception & e) {
		std::cout << "Can't create ellipse, since the points are collinear";
		throw e;
	}
	std::cout << "Choose how you want to build the ellipse:\n1) Three points with center at point (0, 0);\n2) By three points with an offset (you will need to enter 2 more points);\n";
	int choice;
	std::cin >> choice;
	if(choice == 1){
		x0 = 0;
		y0 = 0;
		std::vector<std::vector<double>> equation;
		std::vector<Point> p({p1, p2, p3});
		for(int i = 0; i + 1< p.size(); i++){
			equation.push_back(std::vector<double>({(p[i].x) * (p[i].x), (p[i].y) * (p[i].y), 1}));
		}
		for (int i = 0; i < equation.size(); i++){
			for(int j = 0; j < equation[i].size(); j++){
				std::cout << equation[i][j] << "\t";
			}
			std::cout << "\n";
		}
		Soleq soleq(equation);
		try {
			Soleq::Answer answer = soleq.solve();
			std::vector<std::vector<double>> & a = answer.general_solution;
			if(!answer.thereAreNoFreeUnknown()){
				throw std::invalid_argument("\nWrong data\n");
			}
			this->a = 1/sqrt(a[0][a[0].size() - 1]);
			this->b = 1/sqrt(a[1][a[0].size() - 1]);
			this->r = 1;
			std::cout << "a = " << this->a << ", b = " << this->b << std::endl;
		}
		catch(std::exception & e) {
			std::cout << "Can't create ellipse for this points";
			throw e;
		}
	}
	else if(choice == 2){
		std::vector<std::vector<double>> equation;
		std::vector<Point> p({p1, p2, p3});
		for(int i = 0; i < p.size(); i++){
			equation.push_back(std::vector<double>({1, p[i].x, p[i].y, p[i].x * p[i].x, p[i].y * p[i].y, 0}));
		}
		equation.push_back(std::vector<double> (6,0));
		equation.push_back(std::vector<double> (6,0));
		
		/*for (int i = 0; i < equation.size(); i++){
			for (int j = 0; j < equation[i].size(); j++){
				std::cout << equation[i][j] << "\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n\n";*/
		try {
			const double eps = 0.0001;
			Soleq soleq(equation);
			Soleq::Answer answer = soleq.solve();
			std::vector<std::vector<double>> & a = answer.general_solution;
			/*for (int i = 0; i < a.size(); i++){
				for (int j = 0; j < a[i].size(); j++){
					std::cout << a[i][j] << "\t";
				}
				std::cout << "\n";
			}*/
			std::cout << "Enter variable a (from ellipse equation) : ";
			std::cin >> this->a;
			std::cout << "Enter variable b (from ellipse equation) : ";
			std::cin >> this->b;
			if (fabs(this->a) < eps || fabs(this->b) < eps) {
				throw std::invalid_argument("\nWrong data\n");
			}
			double A,B,C,D,E;
			std::vector<double> res;
			D = 1 / (this->a * this->a);
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
			std::cout << "x0 = " << x0 << ", y0 = " << y0 << std::endl;
		}
		catch (Soleq::Answer & e1) {
			std::cout << "Can't create ellipse for this points";
			throw e1;
		}
		catch (std::invalid_argument & e2) {
			std::cout << "Can't create ellipse for this a, b";
			throw e2;
		}
	}
}

bool myEllipse::isClosed() const {
	return true;
}

