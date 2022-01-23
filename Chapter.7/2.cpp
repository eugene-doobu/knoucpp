#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

stack<string> stk;

int main()
{
	stk.push("hello");
	cout << stk.top();
	stk.pop();
}
