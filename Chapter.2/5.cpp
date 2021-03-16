#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141593;
struct C3dType { // 2차원 좌표 구조체
	double x, y;
};

class CircleClass {
	C3dType center;
	double radius;
public:
	//중심 (cx, cy), 반경 r로 원을 초기화
	void init(double cx, double cy, double r) {
		center.x = cx;
		center.y = cy;
		radius = r;
	}
	double area() const {
		return radius * radius * PI;
	}
	bool chkOverlap(const CircleClass& c)const {
		double dx = center.x - c.center.x;
		double dy = center.y - c.center.y;
		double dCntr = sqrt(dx * dx + dy * dy);
		return dCntr < radius + c.radius;
	}
	void display() const {
		cout << "중심 (" << center.x << ","
			<< center.y << ")";
		cout << "반경 :" << radius << endl;
	}
	void move(double dx, double dy) {
		center.x += dx;
		center.y += dy;
	}
	void setRadius(double r) {
		radius = r;
	}
};

int main() {
	CircleClass c1, c2;
	c1.init(0, 0, 10);
	c2.init(30, 10, 5);

	cout << "원1" << endl;
	c1.display();
	cout << "원1의 면적: " << c1.area() << endl << endl;

	cout << "원2" << endl;
	c2.display();
	cout << "원2의 면적: " << c2.area() << endl << endl;

	// 두 원의 중첩 여부 출력
	if (c1.chkOverlap(c2))
		cout << "두 원은 중첩됩니다." << endl;
	else
		cout << "두 원은 중첩되지 않습니다." << endl << endl;

	c2.move(-20, -5);
	c2.setRadius(15);

	cout << "원2" << endl;
	c2.display();
	cout << "원2의 면적: " << c2.area() << endl << endl;

	// 두 원의 중첩 여부 출력
	if (c1.chkOverlap(c2))
		cout << "두 원은 중첩됩니다." << endl;
	else
		cout << "두 원은 중첩되지 않습니다." << endl;
	return 0;
}