#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    fastio;
    char c; int cnt = 0;
    while (cin.peek() != '$') {
        cin >> c; cnt++;
    }
    cout << cnt;
}
