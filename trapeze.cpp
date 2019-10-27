#include "trapeze.h"
#include <cmath>

Trapeze::Trapeze() : A{0, 0}, B{0, 0}, C{0, 0}, D{0,0} {}

Trapeze::Trapeze(std::istream& in) {
  in >> A >> B >> C >> D;
  double a, c;
  a = sqrt((B.X()- A.X()) * (B.X() - A.X()) + (B.Y() - A.Y()) * (B.Y() - A.Y()));
  c = sqrt((C.X()- D.X()) * (C.X() - D.X()) + (C.Y() - D.Y()) * (C.Y() - D.Y()));
  if(a != c || (C.Y() - B.Y()) / (C.X() - B.X()) != (D.Y() - A.Y()) / (D.X() - A.X()))
    throw std::logic_error("It`s not a isosceles trapeze");
}


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
  if (B.X() == C.X() && D.X() < C.X())
    return Point{D.X() + h - y_, (A.Y() + B.Y() + C.Y() + D.Y()) / 4};
  if (B.X() == C.X() && C.X() < D.X())
    return Point{C.X() + h - y_, (A.Y() + B.Y() + C.Y() + D.Y()) / 4};
  return Point{(A.X() + B.X() + C.X() + D.X()) / 4, (B.Y() + C.Y()) / 2 - ((B.Y() + C.Y()) / 2 - (D.Y() + A.Y()) / 2) * y_ / h};
}

std::ostream& Trapeze::print(std::ostream& out) const
{
  out << A << " " << B << " " << C << " " << D;
  return out;
}

