#include "rhombus.h"
#include <cmath>

Rhombus::Rhombus() : A{0, 0}, B{0, 0}, C{0, 0}, D{0,0} {}

Rhombus::Rhombus(const Point& x, const Point& y, const Point& z, const Point& w) : A{x}, B{y}, C{z}, D{w} {}

double Rhombus::area() const{
  double d1 = sqrt((C.X() - A.X()) * (C.X() - A.X()) + (C.Y() - A.Y()) * (C.Y() - A.Y()));;
  double d2 = sqrt((B.X() - D.X()) * (B.X() - D.X()) + (B.Y() - D.Y()) * (B.Y() - D.Y()));;
  return d1 * d2 / 2;
}

Point Rhombus::center() const
{
	return Point{(A.X() + B.X() + C.X() + D.X()) / 4, (A.Y() + B.Y() + C.Y() + D.Y()) / 4};
}

std::ostream& Rhombus::print(std::ostream& out) const
{
	out << A << " " << B << " " << C << " " << D;
	return out;
}
