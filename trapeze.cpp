#include "trapeze.h"
#include <cmath>

Trapeze::Trapeze() : A{0, 0}, B{0, 0}, C{0, 0}, D{0,0} {}

Trapeze::Trapeze(std::istream& in) {
  in >> A >> B >> C >> D;
  if((C.Y() - B.Y()) / (C.X() - B.X()) != (D.Y() - A.Y()) / (D.X() - A.X()))
    throw std::logic_error("It`s not a trapeze");
}


double Trapeze::area() const{
  return 0.5 * std::abs( A.X() * B.Y() + B.X() * C.Y() + C.X() * D.Y() + D.X() * A.Y() - B.X() * A.Y() - C.X() * B.Y() - D.X() * C.Y() - A.X() * D.Y());	  
}

Point Trapeze::center() const
{
  return Point{(A.X() + B.X() + C.X() + D.X()) / 4, (A.Y() + B.Y() + C.Y() + D.Y()) / 4};
}

std::ostream& Trapeze::print(std::ostream& out) const
{
  out << A << " " << B << " " << C << " " << D;
  return out;
}
