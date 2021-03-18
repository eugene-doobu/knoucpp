#include <iostream>
#include <iomanip>
using namespace std;

int myAbs(int num) {
	cout << "int abs 실행 : ";
	if (num >= 0)
		return num;
	else
		return num * -1;
}

double myAbs(double num) {
	cout << "double abs 실행 : ";
	if (num >= 0)
		return num;
	else
		return num * -1;
}

int main() {
	cout << myAbs(8) << endl;
	cout << myAbs(-4573) << endl;
	cout << myAbs(8.456) << endl;
	cout << myAbs(-1578.8793) << endl;
	return 0;
}