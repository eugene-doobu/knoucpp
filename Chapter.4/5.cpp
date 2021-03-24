#include <iostream>
#include <iomanip>
using namespace std;

class CharStack {
	int size;
	int top;
	char *buf;
public:
	CharStack(int size) : top{ size }, size{ size } {
		buf = new char[top];
	}
	~CharStack() {
		delete[] buf;
	}
	bool chkEmpty() const {
		return top == size;
	}
	bool chkFull() const {
		return !top;
	}
	bool push(char ch);
	char pop();
};
bool CharStack::push(char ch) {
	if (chkFull()) {
		cout << "스택이 가득 차 있습니다." << endl;
		return false;
	}
	buf[--top] = ch;
	return true;
}
char CharStack::pop() {
	if (chkEmpty()) {
		cout << "스택에 데이터가 없습니다." << endl;
		return 0;
	}
	return buf[top++];
}


int main() {
	CharStack chStack(20);
	char str[20];

	cout << "영어 단어를 입력하시오:";
	cin >> str;

	char* pt = str;
	while (*pt)
		chStack.push(*(pt++));

	cout << "역순 단어 출력:";
	while (!chStack.chkEmpty())
		cout << chStack.pop();
	cout << endl;
	return 0;
}