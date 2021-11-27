#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class BaseC {
    int x;
public:
    BaseC(int a) : x(a) {};
    virtual void Print() const { cout << x; };
};

class DrvC : public BaseC {
    int y;
public:
    DrvC(int a, int b) : BaseC(a), y(b) {};
    void Print() const {
        BaseC::Print();
        cout << " " << y; 
    }
};

int main()
{
    BaseC* pt1 = new BaseC(10);
    BaseC* pt2 = new DrvC(100, 200);
    pt1->Print();
    cout << endl;
    pt2->Print();
    return 0;
};