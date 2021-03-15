#include <iostream>

int main() {
	char str[100];
	std::cin.getline(str, 100);

	char *pt;
	pt = str;
	int result = 0;

	while (*pt) {
		if (isdigit(*pt)) result++;
		pt++;
	}

	std::cout << result;
	return 0;
}