//
// Created by sc on 2023/3/30.
//
#include <iostream>

void testStaticCast()
{
    uint32_t x = 1;
    int y = static_cast<int>(x); // right

    std::cout<< y <<std::endl;   // 1

    int a = 1;
    double b = static_cast<double>(x); // right
    std::cout<< b <<std::endl;  // 1

    int c = -1;
    uint32_t d = static_cast<uint32_t>(c); // error
    std::cout<< d <<std::endl; // 4294967295

    double e = 1.22;
    int f = static_cast<int>(e); // 精度缺失
    std::cout<< f <<std::endl; // 1

    class Base{};
    class Derive:public Base{};
    // 上行转换，派生类→基类 safe
    Derive* derive = new Derive();
    Base* base = static_cast<Base*>(derive);

    // 下行转换，基类→派生类 unsafe
    Base* base1 = new Base();
    Derive* derive1 = static_cast<Derive*>(base1);
}

void testDynamicCast()
{
    class Base {
    public:
        virtual void Say() {
            std::cout << "I am Base." <<  std::endl;
        }
    };

    class Derive : public Base {
    public:
        virtual void Say() {
            std::cout << "I am Derive." <<  std::endl;
        }
    };
    // 上行转换
    Derive* d1 = new Derive();
    std::cout << "d1: " << d1 << std::endl;

    Base* b1 = dynamic_cast<Base*>(d1);
    std::cout << "b1: " << b1 <<  std::endl;

    // 下行转换
    Base* b2 = new Base();
    std::cout << "b2: " << b2 <<  std::endl;

    Derive* d2 = dynamic_cast<Derive*>(b2);
    std::cout << "d2: " << d2 <<  std::endl;

}

void testConstCast()
{
    using namespace std;
    int x = 1;
    cout << "before: " << x << endl;

    const int* px = &x;
    // *px = 2; // 编译错误
    int* py = const_cast<int*>(px);
    *py = 2;
    cout << "px addr:" << &px << endl;
    cout << "py addr: " << &py << endl;
    cout << "px source" << px << endl;
    cout << "py source" << py << endl;
    cout << "after : " << x << endl;
}
int main()
{
    //testStaticCast();
    //testDynamicCast();
    testConstCast();
}