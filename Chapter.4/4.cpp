#include <iostream>
#include <iomanip>
using namespace std;

class IntQueue
{
	int size;
	int front = 0;
	int rear = 0;
	int *buf;

public:
	IntQueue(int size) : size{size}
	{
		buf = new int[size];
	}
	~IntQueue()
	{
		delete[] buf;
	}
	bool chkEmpty() const
	{
		return front == rear;
	}
	bool chkFull() const
	{
		return front >= size;
	}
	bool enqueue(int ch);
	int dequeue();
};
bool IntQueue::enqueue(int val)
{
	if (chkFull())
	{
		cout << "큐가 가득 차 있습니다." << endl;
		return false;
	}
	buf[front++] = val;
	return true;
}
int IntQueue::dequeue()
{
	if (chkEmpty())
	{
		cout << "큐에 데이터가 없습니다." << endl;
		return 0;
	}
	return buf[rear++];
}

int main()
{
	IntQueue intQueue(5);
	int arr[5];

	for (int i = 0; i < 5; i++)
	{
		cout << i << "번 숫자를 입력해주세요:";
		cin >> arr[i];
	}

	int *pt = arr;
	while (*(pt + 1))
	{
		intQueue.enqueue(*(pt++));
	}

	cout << "입력 숫자 출력:";
	while (!intQueue.chkEmpty())
		cout << intQueue.dequeue() << " ";
	cout << endl;
	return 0;
}