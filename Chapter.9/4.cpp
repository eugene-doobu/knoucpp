#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void CoutSqrtPow(int num) {
    cout.precision(5);
    cout.fill('*');
    cout << "num: " << num << "\n";

    cout << "pow : ";
    cout.width(10);
    cout << pow(num, 2) << "\n";

    cout << "sqrt: ";
    cout.width(10);
    cout << sqrt(num) << "\n";
    cout << "\n";
}

int main() {
    fastio;
    for (int i = 2; i <= 20; ++i) {
        CoutSqrtPow(i);
    }
}
