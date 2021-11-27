#include <iostream>
#include "Circle.h"

const double PI = 3.14159265358979323846;
using namespace std; 

void Circle::move(double dx, double dy) {
	cx += dx;
	cy += dy;
}

void Circle::scale(double s) {
	cx *= s;
	cy *= s;
	radius *= s;
}

void Circle::draw() const {
	cout << "�� �׸��� : " << endl;
	cout << " (" << cx << ", " << cy << ")�������� ";
	cout << radius << "��ŭ ������ ��� ������ ";
	cout << attrib.getLineColor() << "���� �׸��� " << endl;
	cout << "  ���θ� " << attrib.getFillColor() << "���� ä���." << endl;
}

void Circle::area() const {
	cout << "���� : " << PI * PI * radius << endl;
}