#include <iostream>
using namespace std;

int* pibo;

// a[0] = 1, a[1] = 1
// a[i] = a[i-1] + a[i-2], i>=2
int PiboFunc(int num) {
	if (num <= 1) {
		*(pibo + num) = 1;
		return 1;
	}
	if (*(pibo + num) != 0) {
		return *(pibo + num);
	}
	*(pibo + num) = PiboFunc(num - 1) + PiboFunc(num - 2);
	return *(pibo + num);
}

int main() {
	// 선언부
	int num = 0;
	cin >> num;
	pibo = new int[num];

	// 배열 초기화
	for (int i = 0; i < num; i++) {
		*(pibo + i) = 0;
	}

	// 피보나치수 계산(인덱스가 0부터 시작해서 -1)
	PiboFunc(num-1);

	// 출력
	for (int i = 0; i < num; i++) {
		cout << *(pibo + i) << endl;
	}

	// 종료
	delete[] pibo;
	return 0;
}