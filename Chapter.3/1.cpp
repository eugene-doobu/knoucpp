#include <iostream>

int strcmp(const char* str1, const char* str2) {
	for (int i = 0; i < 10; i++) {
		if (*(str1 + i) > *(str2 + i))
			return 1;
		if (*(str1 + i) < *(str2 + i))
			return -1;
	}
	return 0;
}

int main() {
	char s1[10], s2[10];
	std::cin >> s1;
	std::cin >> s2;

	std::cout << strcmp(s1, s2);

	return 0;
}
/* 출력결과
* 
* str1 : abc
* str2 : abc
* 0
* 
* str1 : bbc
* str2 : abc
* 1
* 
* str1 : abc
* str2 : bbc
* -1
*/