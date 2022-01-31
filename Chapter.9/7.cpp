#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

int main() {
    string fileName = "./test.txt";
    char ch; int b = 0;

    ifstream fin(fileName);

    // 2byte 고려 안함
    while (fin.get(ch)) {
        cout << ch; b += 1;
    }
    fin.close();

    cout << "글자수: " << b;
}