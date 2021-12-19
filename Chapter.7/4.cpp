#pragma warning(disable:4996)
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

template<typename T>
class LESS_T {
public:
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

int main() {
    multimap<string, string, LESS_T<string>> pBook{
        {"한정훈", "010-2233-4353"},
        {"박영철", "010-2233-4455"}
    };

    pBook.insert(make_pair("김철수", "010-1234-5678"));
    pBook.insert(make_pair("최승호", "010-7531-3456"));
    pBook.insert(make_pair("박영철", "010-1357-2468"));

    for (auto pb = pBook.begin(); pb != pBook.end(); ++pb)
        cout << pb->first << " " << pb->second << endl;
    cout << pBook.size() << "명이 등록되어 있습니다." << endl;

    string str;
    cout << endl << "찾을 이름: ";
    cin >> str;
    auto result = pBook.find(str);
    if (result != pBook.end()) {
        cout << result->first << "님의 전화번호는";
        cout << result->second << " 입니다." << endl;
    }
    else {
        cout << str << "님을 찾을 수 없습니다." << endl;
    }
    return 0;
}