#include <iostream>

double power(double a, int b = 2) {
	double origin = a;
	for (int i = 1; i < b; i++) {
		a *= origin;
	}
	return a;
}

int main() {
	std::cout << power(10, 3) << std::endl;
	std::cout << power(2);

	return 0;
}