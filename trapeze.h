#ifndef TRAPEZE_H
#define TRAPEZE_H

#include "figure.h"
#include "point.h"

class Trapeze : public Figure {
public:
        Trapeze();
        Trapeze(const Point& x, const Point& y, const Point& z, const Point& w);
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
