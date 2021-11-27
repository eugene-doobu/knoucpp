#ifndef FIGURE_H_INCLUDED
#define FIGURE_H_INCLUDED

#include "GrAttrib.h"

class Figure {  // 추상클래스
protected:
	GrAttrib attrib;
public:
	Figure() : attrib(curAttrib) {}
	void setLineColor(const string& c) { attrib.setLineColor(c); }
	void setFillColor(const string& c) { attrib.setFillColor(c); }
	virtual void move(double dx, double dy) = 0;
	virtual void scale(double s) = 0;
	virtual void draw() const = 0;
	virtual void area() const = 0;
};
#endif