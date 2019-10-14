#include "rectangle.h"
#include <cmath>

Rectangle::Rectangle() : A{0, 0}, B{0, 0}, C{0,0}, D{0,0} {}

Rectangle::Rectangle(const Point& x, const Point& y, const Point& z, const Point& w) : A{x}, B{y}, C{z}, D{w} {}

double Rectangle::area() const{
  double a =  sqrt((B.X() - A.X()) * (B.X() - A.X()) + (B.Y() - A.Y()) * (B.Y() - A.Y()));
  double b =  sqrt((C.X() - B.X()) * (C.X() - B.X()) + (B.Y() - C.Y()) * (B.Y() - C.Y()));;
  return a * b;
}

Point Rectangle::center() const{
  return Point{(A.X() + B.X() + C.X() + D.X()) / 4, (A.Y() + B.Y() + C.Y() + D.Y()) / 4};
}

std::ostream& Rectangle::print(std::ostream& out) const{
  out << A << " " << B << " " << C << " " << D;
  return out;
}
