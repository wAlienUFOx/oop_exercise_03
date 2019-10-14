#ifndef RECTNAGLE_H
#define RECTNAGLE_H

#include "figure.h"
#include "point.h"

class Rectangle : public Figure {
public:
	Rectangle();
	Rectangle(const Point& x, const Point& y, const Point& z, const Point& w);
	double area() const override;
	Point center() const override;
	std::ostream& print(std::ostream& out) const override;
private:
	Point A;
	Point B;
	Point C;
	Point D;
};

#endif
