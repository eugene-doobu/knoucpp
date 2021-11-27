#include "Figure.h"

class Circle : public Figure {
	double cx, cy;
	double radius;
public:
	Circle(double x, double y, double r) : cx(x), cy(y), radius(r) {}
	void draw() const;
	void area() const;
	void move(double dx, double dy);
	void scale(double s);
};