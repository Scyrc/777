//
// Created by sc on 2023/8/29.
//
#include <iostream>
using namespace std;

struct TestStruct
{
    int x;
    int y;
    TestStruct() = default;
    void add()
    {
        x += 1;
        y += 1;
    }
};
class TestClass
{
public:
    static int value1;  // 存储在全局数据区
    static inline int value2 = 2;  // 存储在全局数据区
    mutable int value3 = 3;          //存储在类实例化对象 mutable
    int value4 = 4;
    int value5 = 5;
    void constFun1(const int& value) const
    {
        value3 = value;
        //value4 = value; error
    }

    void Fun2(int& v, int* p)
    {
        p = &v;
        *p = 2;
    }
};

int TestClass::value1 = 1;

int main()
{
    TestClass TestInstance{};

   /* std::cout << &TestClass::value1 << std::endl;
    std::cout << &TestClass::value2 << std::endl;
    std::cout << &TestInstance.value3 << std::endl;
    std::cout << &TestInstance.value4 << std::endl;*/
    /*int v0 = 0, v1 = 1;
    int *p = &v1;
    TestInstance.Fun2(v0, p);
    std::cout << v0 << std::endl;
    std::cout << v1 << std::endl;
    std::cout << *p << std::endl;*/

    TestClass* p1 = &TestInstance;
    TestClass& t1 = TestInstance;

    std::cout<< sizeof(p1) << std::endl;
    std::cout<< sizeof(*p1) << std::endl;

    std::cout<< sizeof(t1) << std::endl;

    /*TestStruct TestInstance1{};
    TestInstance1.add();
    TestInstance1.add();
    std::cout << TestInstance1.x << std::endl;
    std::cout << TestInstance1.y << std::endl;*/
}