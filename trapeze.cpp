#include "trapeze.h"
#include <cmath>

Trapeze::Trapeze() : A{0, 0}, B{0, 0}, C{0, 0}, D{0,0} {}

Trapeze::Trapeze(const Point& x, const Point& y, const Point& z, const Point& w) : A{x}, B{y}, C{z}, D{w} {}

double Trapeze::area() const{
  double a = sqrt((C.X() - B.X()) * (C.X() - B.X()) + (B.Y() - C.Y()) * (B.Y() - C.Y()));
  double b = sqrt((B.X() - A.X()) * (B.X() - A.X()) + (B.Y() - A.Y()) * (B.Y() - A.Y()));
  double l = sqrt((D.X() - A.X()) * (D.X() - A.X()) + (A.Y() - D.Y()) * (A.Y() - D.Y()));
  double c = (l - a) / 2;
  double h = sqrt((b * b) - (c * c));
  return 0.5 * h * (a + l);
	       
}

Point Trapeze::center() const
{
  double a = sqrt((C.X() - B.X()) * (C.X() - B.X()) + (B.Y() - C.Y()) * (B.Y() - C.Y()));
  double b = sqrt((B.X() - A.X()) * (B.X() - A.X()) + (B.Y() - A.Y()) * (B.Y() - A.Y()));
  double l = sqrt((D.X() - A.X()) * (D.X() - A.X()) + (A.Y() - D.Y()) * (A.Y() - D.Y()));
  double c = (l - a) / 2;
  double h = sqrt((b * b) - (c * c));
  double y_ = (2 * l + a) * h / (a + l) / 3;
  return Point{(A.X() + B.X() + C.X() + D.X()) / 4, (B.Y() + C.Y()) / 2 - ((B.Y() + C.Y()) / 2 - (D.Y() + A.Y()) / 2) * y_ / h   };
}

std::ostream& Trapeze::print(std::ostream& out) const
{
  out << A << " " << B << " " << C << " " << D;
  return out;
}

