#ifndef PARABOLA_HPP
#define PARABOLA_HPP

#include "curve.hpp"
#include <vector>
class Parabola : public Curve{
protected:
	bool vertical;
	double p;
	
public:
	
	Parabola(const Point & p1, const Point & p2, const Point & p3, bool vertical = true);
	
	double getP() const;
	
	double getX(double t) const;

	double getY(double t) const;

	
	virtual bool isClosed() const;
	
	std::vector<Point> tangentVector(double t) const;
};

#endif
