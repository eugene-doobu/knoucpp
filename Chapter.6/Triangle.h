#include "Figure.h"

class Triangle : public Figure {
	double x1, y1, x2, y2, x3, y3;
protected:
	GrAttrib attrib;
public:
	Triangle(const double v[3][2]);
	void draw() const;
	void area() const;
	void move(double dx, double dy);
	void scale(double s);
};