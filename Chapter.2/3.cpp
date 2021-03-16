#include <iostream>

int main() {
	int table[3][2];
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 3; i++) {
			table[i][j] = i * j;
			std::cout << table[i][j];
		}
		std::cout << std::endl;
	}
	return 0;
}