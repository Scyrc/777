//
// Created by sc on 2023/4/2.
//
#include <iostream>
#include <cstring>

class Vector{
    int num;
    int* a;
public:
    void ShallowCopy(Vector& v);
    void DeepCopy(Vector& v);
    Vector() = default;

    //拷贝构造函数：这意味着深拷贝
    Vector(Vector& v){
        this->num = v.num;
        this->a = new int[num];
        for(int i=0;i<num;++i){a[i]=v.a[i];}
    }
//移动构造函数：这意味着浅拷贝
    Vector(Vector&& temp){
        this->num = temp.num;
        this->a = temp.a;
        temp.a = nullptr;    //实际上Vector一般都会在析构函数来释放指向的内存，所以需赋值空地址避免释放
    }
};
//浅拷贝
void Vector::ShallowCopy(Vector& v){
    this->num = v.num;
    this->a = v.a;
    v.a = nullptr;
}
//深拷贝
void Vector::DeepCopy(Vector& v){
    this->num = v.num;
    this->a = new int[num];
    for(int i=0;i<num;++i){a[i]=v.a[i];}
}

void test(Vector& o) {std::cout << "left" << std::endl;}
void test(Vector&& temp) {std::cout << "right" << std::endl;}


class CMyString{
public:
    char* m_pBuffer;
    int m_iLen;
    CMyString(const char* pString){
        m_iLen = strlen(pString) + 1;
        m_pBuffer = new char[m_iLen];
        strcpy(m_pBuffer, pString);
    }
    ~CMyString(){
        m_iLen = 0;
        if(m_pBuffer){
            delete[] m_pBuffer;
        }
    }
    CMyString(CMyString& other){
        // 深拷贝
        std::cout<<"deep copy"<<std::endl;
        this->m_iLen = other.m_iLen;
        this->m_pBuffer = new char[m_iLen];
        strcpy(this->m_pBuffer, other.m_pBuffer);
    }
    CMyString(CMyString&& other) noexcept {
        std::cout<<"shallow copy"<<std::endl;
        this->m_iLen = other.m_iLen;
        this->m_pBuffer = other.m_pBuffer; // 浅拷贝、偷资源
        other.m_pBuffer = nullptr;         // 让 m_pBuffer 不因为other析构而释放
    }

    CMyString& operator=(const CMyString& other)
    {
        // 深拷贝
        if(this == &other) return *this;
        std::cout<<"copy ="<<std::endl;
        this->m_iLen = other.m_iLen;
        this->m_pBuffer = new char[m_iLen];
        strcpy(this->m_pBuffer, other.m_pBuffer);
        return *this;
    }

    // move =
    CMyString& operator=(CMyString&& other) noexcept
    {
        if(this == &other) return *this;
        std::cout<<"move ="<<std::endl;
        this->m_iLen = other.m_iLen;
        this->m_pBuffer = other.m_pBuffer; // 浅拷贝、偷资源
        other.m_pBuffer = nullptr;         // 让 m_pBuffer 不因为other析构而释放
        return *this;
    }
};


// 防止编译器优化
CMyString return_rvalue(bool test) {
    CMyString a("123"),b("456");
    if(test) return a; // 等价于 static_cast<A&&>(a);
    else return b;     // 等价于 static_cast<A&&>(b);
}

void testString()
{
    CMyString str1 = return_rvalue(false);
    std::cout << str1.m_iLen<<std::endl;
}
template<typename T>
void myswap(T& a, T& b){
    T temp(a);  // 发生拷贝构造
    a = b;      // 发生拷贝赋值
    b = temp;   // 发生拷贝赋值
}
template<typename T>
void myswap_move(T& a, T& b){
    T temp(std::move(a));  // 发生移动构造
    a = std::move(b);      // 发生移动赋值
    b = std::move(temp);   // 发生移动赋值
}
void testStdMove()
{
    CMyString str1("123");
    CMyString str2("565");
    myswap(str1, str2);
    myswap_move(str1, str2);
}
int funcA(int a) { return a;}
int& funcB(int a) { return a;}
class A { public: A(){} ~A(){} };
void RValue()
{
    //auto pos_num = &(10);  // 不能取地址 1. 常量字面量
    auto pos_char = &("123456");  // "123456" 类型为 const char [7]，因此是左值
    //auto pos_funA = &(funcA(0x1111)); // 不能取地址 2. 函数调用的返回值
    auto pos_funB = &(funcB(0x2222)); // 函数调用返回的类型为左值引用，则返回的结果为左值
    //auto pos_class = &(A()); //不能取地址 3. 无名对象
}
void reference(std::string& str) {
    std::cout << "左值" << std::endl;
}
void reference(std::string&& str) {
    std::cout << "右值" << std::endl;
}

void RVReference()
{
    std::string lv1 = "string,"; // lv1 是一个左值
    // std::string&& r1 = lv1; // 非法, 右值引用不能引用左值
    std::string&& rv1 = std::move(lv1); // 合法, std::move可以将左值转移为右值
    std::cout << rv1 << std::endl; // string,

    const std::string& lv2 = lv1 + lv1; // 合法, 常量左值引用能够延长临时变量的生命周期
    // lv2 += "Test"; // 非法, 常量引用无法被修改
    std::cout << lv2 << std::endl; // string,string,

    std::string&& rv2 = lv1 + lv2; // 合法, 右值引用延长临时对象生命周期
    rv2 += "Test"; // 合法, 非常量引用能够修改临时变量
    std::cout << rv2 << std::endl; // string,string,string,Test
    reference(rv2); // 输出左值
}

void reference(int& v) {
    std::cout << "左值引用" << std::endl;
}
void reference(int&& v) {
    std::cout << "右值引用" << std::endl;
}
template <typename T>
void pass(T&& v) {
    std::cout << "              普通传参: ";
    reference(v);
    std::cout << "       std::move 传参: ";
    reference(std::move(v));
    std::cout << "    std::forward 传参: ";
    reference(std::forward<T>(v));
    std::cout << "static_cast<T&&> 传参: ";
    reference(static_cast<T&&>(v));
}

int main(){
/*    Vector a;
    Vector&& b = Vector();
    //请分别回答：a、std::move(a)、b 分别是左值还是右值？
    test(a);
    test(std::move(a));
    test(b);*/

    //testString();

    //testStdMove();

    std::cout << "传递右值:" << std::endl;
    pass(1);

    std::cout << "传递左值:" << std::endl;
    int v = 1;
    pass(v);

    return 0;
}
