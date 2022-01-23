#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

template<class T, int size>
class CQueue {
private:
	T queue[size+1];
	int front = 0;
	int rear = 0;
public:
	bool isEmpty() {
		return front == rear;
	}
	bool isFull() {
		return front == ((rear + 1) % (size + 1));
	}
	bool Enqueue(T item) {
		if (isFull()) return false;
		rear = (rear + 1) % (size + 1);
		queue[rear] = item;
		return true;
	}
	T Dequeue() {
		if (isEmpty()) return NULL;
		front = (front + 1) % (size + 1);
		return queue[front];
	};
};

int main()
{
	CQueue<int, 5> icq;
	for (int i = 0; i < 2; ++i) {
		for (int j = 1; j <= 6; ++j) {
			icq.Enqueue(j);
		}
		for (int j = 1; j <= 6; ++j) {
			cout << icq.Dequeue() << "\n";
		}
	}
}
