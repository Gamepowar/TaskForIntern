#include "circle.hpp"

void Circle::showInfo() const {
	std::cout << "Circle Info:\n";
	std::cout << "r = " << r << "\n";
	std::cout << "x0 = " << x0 << "\n";
	std::cout << "y0 = " << y0 << "\n";
	std::cout << std::endl;
}

Circle::Circle(const Point & p1, const Point & p2, const Point & p3){
	std::cout << "Creating circle\n";
	try {
		setPoint(p1, p2, p3);
	}
	catch (std::exception & e) {

		std::cout << "Can't create circle, since the points are collinear\n\n";
		throw e;
	}
	std::vector<std::vector<double>> equation;
	std::vector<Point> p({p1, p2, p3});
	for(int i = 0; i < p.size(); i++){
		equation.push_back(std::vector<double>({p[i].x, p[i].y, 1, p[i].x * p[i].x + p[i].y * p[i].y}));
	}
	Soleq soleq(equation);
	try {
		Soleq::Answer answer = soleq.solve();
		std::vector<std::vector<double>> & a = answer.general_solution;

		if(!answer.thereAreNoFreeUnknown()){
			throw std::invalid_argument("\nWrong data\n");
		}
		x0 = a[0][a[0].size()-1]/2;
		y0 = a[1][a[0].size() - 1]/2 ;
		r = sqrt(pow(x0 - p1.x, 2) + pow(y0 - p1.y, 2));

		std::cout << "r = " << r << std::endl;
		std::cout << "x0 = " << x0 << ", y0 = " << y0 << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception & e) {
		std::cout << "Can't create circle for this points\n\n" << std::endl;

		throw e;
	}
}

double Circle::getX(double t) const {
	return r * cos(t) + x0;
}

double Circle::getY(double t) const {
	return r * sin(t) + y0;
}

double Circle::getR() const {
	return r;
}

bool Circle::isClosed() const {
	return true;
}

std::vector<Point> Circle::tangentVector(double t) const {
	const double eps = 0.0001;
	double x = getX(t);
	double y = getY(t);
	double shift = 1;
	Point p1(x, y);
	Point p2(x + shift, -((x + shift - x0) * x + (-x0 * x - y0 * y + x0 * x0 + y0 * y0 - r * r))/ y0 + y);
	if (fabs(p2.y - p1.y) < eps) {
		p2.x -= shift;
		p2.y += shift;
	}
	return std::vector<Point>({p1, p2});
}

