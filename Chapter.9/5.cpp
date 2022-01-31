#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

void center(char* s) {
    int i = 0;
    while (*(s + i) != '\0') i++;
    cout.width(40 + (i/2));
    cout << s << "\n";
}

int main() {
    fastio;
    char s[81]; cin.getline(s, 81);
    center(s);
}
