//
// Created by sc on 2023/3/31.
//

#include <iostream>
using namespace std;

class Base {
public:
    int a;
    virtual void f() { cout << "f()" << endl; }
    virtual void g() { cout << "g()" << endl; }
    virtual void h() { cout << "h()" << endl; }
};

int main()
{
    Base t;

    cout<<sizeof(t)<<endl;
    return 0;
}