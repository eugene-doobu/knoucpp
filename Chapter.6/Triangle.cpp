#include <iostream>
#include "Triangle.h"
using namespace std;

Triangle::Triangle(const double v[3][2]) {
	x1 = v[0][0];  y1 = v[0][1];
	x2 = v[1][0];  y2 = v[1][1];
	x3 = v[2][0];  y3 = v[2][1];
}

void Triangle::move(double dx, double dy) {
	x1 += dx;  y1 += dy;
	x2 += dx;  y2 += dy;
	x3 += dx;  y3 += dy;
}

void Triangle::scale(double s) {
	x1 *= s;  y1 *= s;
	x2 *= s;  y2 *= s;
	x3 *= s;  y3 *= s;
}

void Triangle::draw() const {
	cout << "삼각형 그리기 : " << endl;
	cout << " (" << x1 << ", " << y1 << "), ";
	cout << " (" << x2 << ", " << y2 << "), ";
	cout << " (" << x3 << ", " << y3 << "), ";
	cout << attrib.getLineColor() << "으로 그리고 " << endl;
	cout << "  내부를 " << attrib.getFillColor() << "으로 채운다." << endl;
}

void Triangle::area() const {
	auto first  = (x1 * y2) + (x2 * y3) + (x3 * y1);
	auto second = (y1 * x2) + (y2 * x3) + (y3 * x1);
	auto re = (first - second) * 0.5;
	re = re >= 0 ? re : re * -1;
	cout << "면적 : " << re << endl;
}