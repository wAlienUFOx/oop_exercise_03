#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figure.h"
#include "point.h"

class Rhombus : public Figure {
public:
	Rhombus();
	Rhombus(std::istream& in);
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
