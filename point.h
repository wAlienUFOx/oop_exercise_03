#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
	Point();
	Point(double x, double y);
	double X() const;
	double Y() const;
private:
	double x;
	double y;
};

bool operator== (const Point& x, const Point& y);
std::ostream& operator<< (std::ostream& out, const Point& p);

#endif
