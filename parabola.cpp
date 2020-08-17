#include "soleq.hpp"
#include "parabola.hpp"

void Parabola::showInfo() const {
	std::cout << "Parabola Info:\n";
	std::cout << "p (focal parameter) = " << p << "\n";
	std::cout << "x0 = " << x0 << "\n";
	std::cout << "y0 = " << y0 << "\n";
	std::cout << "Parabola is " << (vertical ? "vertical" : "horizontal") << std::endl;
	std::cout << std::endl;
}

Parabola::Parabola(const Point & p1, const Point & p2, const Point & p3, bool vertical){
	std::cout << "Creating " << (vertical ? "verical" : "horizontal") << " parabola\n";
	try {
		setPoint(p1, p2, p3);
	}
	catch (std::exception & e) {
		std::cout << "Can't create parabola, since the points are collinear\n\n";
		throw e;
	}
	this->vertical = vertical; 
	std::vector<std::vector<double>> equation;
	std::vector<double> temp;
	std::vector<Point> p({p1, p2, p3});
	for(int i = 0; i < p.size(); i++){
		if(vertical){
			temp = std::vector<double>({p[i].x * p[i].x, p[i].x, 1, p[i].y});
		}
		else{
			temp = std::vector<double>({p[i].y * p[i].y, p[i].y, 1, p[i].x});
		}
		equation.push_back(temp);
		temp.clear();
	}
	Soleq soleq(equation);
	try {
		Soleq::Answer answer = soleq.solve();
		std::vector<std::vector<double>> & a = answer.general_solution;
		if(!answer.thereAreNoFreeUnknown()){
			throw std::invalid_argument("\nWrong data\n");
		}
		double a1,b1,c1;
		a1 = a[0][a[0].size()-1];
		b1 = a[1][a[0].size() - 1];
		c1 = a[2][a[0].size()-1];
		//std::cout << a1 << " " << b1 << " " << c1 << std::endl;
		if(vertical){
			x0 = -b1 / (2 * a1);
			y0 = -(b1*b1 - 4 * a1 * c1) / (4 * a1); 
		}
		else{
			y0 = -b1 / (2 * a1);
			x0 = -(b1*b1 - 4 * a1 * c1) / (4 * a1); ;
		}
		this->p = 1/ (2 * a1);
		if (fabs(this->p) < 0.0001) {
			throw std::invalid_argument("\nWrong data\n");
		}
		std::cout << "p (focal parameter) = " << this->p << std::endl;
		std::cout << "x0 = " << x0 << ", y0 = " << y0 << std::endl;
		std::cout << "Parabola is " << (vertical ? "vertical" : "horizontal") << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Can't create " << (vertical ? "vertical" : "horizonal") << " parabola for this points\n\n";
		throw e;
	}
}

double Parabola::getP() const {
	return p;
}

double Parabola::getX(double t) const {
	return vertical ? (t + x0 ): (t * t / (2 * p) + x0);
}
double Parabola::getY(double t) const {
	return vertical ? (t * t / (2 * p) + y0) : (t + y0);
}

bool Parabola::isClosed() const {
	return false;
}

std::vector<Point> Parabola::tangentVector(double t) const {
	double x = getX(t);
	double y = getY(t);
	return std::vector<Point>({Point(x, y), Point(x + 1, (x / p - x0 / p)*(x + 1) + x0 * x0*(2 * p))});
}

