#include <bits/stdc++.h>
using namespace std;

double divide(double a, double b) {
	if (b == 0) throw "0으로 나눌 수 없습니다.";
	return a / b;
}
int main()
{
	try {
		cout << divide(5, 0);
	}
	catch(const char* s){
		cout << s;
	}
}
