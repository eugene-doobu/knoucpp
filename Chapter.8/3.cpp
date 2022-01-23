#include <bits/stdc++.h>
using namespace std;

/// <summary>
/// 문제 조건과 달리 stack이 아닌 CQueue로 구현
/// </summary>
template<class T, int size>
class CQueue {
private:
	T queue[size + 1];
	int front = 0;
	int rear = 0;
public:
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return front == ((rear + 1) % (size + 1));
	}
	void Enqueue(T item) {
		if (isFull()) throw "CQueue is full!!";
		rear = (rear + 1) % (size + 1);
		queue[rear] = item;
	}
	T Dequeue() {
		if (isEmpty()) throw "CQueue is Empty!!";
		front = (front + 1) % (size + 1);
		return queue[front];
	};
};

int main()
{
	CQueue<int, 5> icq;
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= 6; ++j) {
			try {
				icq.Enqueue(j);
			}
			catch (const char* s) {
				cout << s << "\n";
			}
		}
		for (int j = 1; j <= 6; ++j) {
			try {
				cout << icq.Dequeue() << "\n";
			}
			catch (const char* s) {
				cout << s << "\n";
			}
		}
	}
}
