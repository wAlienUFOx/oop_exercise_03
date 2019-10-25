#ifndef TRAPEZE_H
#define TRAPEZE_H

#include "figure.h"
#include "point.h"

class Trapeze : public Figure {
public:
        Trapeze();
	Trapeze(std::istream& in);
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
