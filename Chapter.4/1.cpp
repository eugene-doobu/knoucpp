#include <iostream>
#include <iomanip>
using namespace std;

class Box {
	float height, width, depth;
public:
	Box(float height, float width, float depth)
		: height{ height }, width{ width }, depth{ depth } {}
	float volume() const {
		return height * width * depth;
	}
};


int main() {
	Box box1(2, 3, 4);
	Box box2(10, 20, 30);

	cout << box1.volume() << endl;
	cout << box2.volume() << endl;
}