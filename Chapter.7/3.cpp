#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	auto reverse = [](int a, int b) {
		return a > b;
	};

	vector<int> iv1(5);
	cout << "벡터1: ";
	for (auto& i : iv1) {
		i = rand() % 100;
		cout << i << " ";
	}
	sort(iv1.begin(), iv1.end(), reverse);
	cout << endl << "정렬된 벡터 1 : ";
	for (auto i : iv1) {
		cout << i << " ";
	}
	cout << endl << endl;


	vector<int> iv2(5);
	cout << "벡터2: ";
	for (auto& i : iv2) {
		i = rand() % 100;
		cout << i << " ";
	}
	sort(iv2.begin(), iv2.end(), reverse);
	cout << endl << "정렬된 벡터 2 : ";
	for (auto i : iv2) {
		cout << i << " ";
	}
	cout << endl << endl;

	// 합병 결과를 저장할 벡터
	vector<int> iv3(iv1.size() + iv2.size());
	merge(iv1.begin(), iv1.end(), iv2.begin(), iv2.end(), iv3.begin(), reverse);
	cout << "벡터1과 벡터2를 합병한 결과 : ";
	for (auto i : iv3) {
		cout << i << " ";
	}
	cout << endl << endl;

	return 0;
}

