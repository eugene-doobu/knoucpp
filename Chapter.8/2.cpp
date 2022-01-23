#include <bits/stdc++.h>
using namespace std;

int main()
{
	try {
		unique_ptr<int[]> p{ new int[10000000] };
	}
	catch (const bad_alloc) {
		cout << "배열이 너무 큽니다.";
	}
}
