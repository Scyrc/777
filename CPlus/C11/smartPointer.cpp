//
// Created by sc on 2023/3/30.
//
#include <iostream>
#include <assert.h>
#include <memory>

template<typename T>
struct MyDeleter
{
    void operator() (const T* Ptr)
    {
        if(Ptr == nullptr) return;
        delete Ptr;
        Ptr = nullptr;
        std::cout<< "delete ptr"<<std::endl;
    }
};

struct Fruit {
    int juice;
};

struct Vegetable {
    int fiber;
};

struct Tomato : public Fruit, Vegetable {
    int sauce;

    Tomato(int v) : Fruit(), Vegetable() { sauce = v;}
};
void testUniquePtr()
{
    std::unique_ptr<Tomato> uptr = std::make_unique<Tomato>(1);
    uptr.reset(new Tomato(2));
}
void testSharePtr()
{
    std::shared_ptr<int> sptr = std::make_shared<int>(200);
    assert(sptr.use_count() == 1);  // 此时引用计数为 1

    {
        std::shared_ptr<int> sptr1 = sptr;
        assert(sptr1.get() == sptr.get());
        assert(sptr.use_count() == 2);
    }
    assert(sptr.use_count() == 1);

    std::cout << sizeof(int*) << std::endl;  // 输出 8
    std::cout << sizeof(std::unique_ptr<int>) << std::endl;  // 输出 8
    std::cout << sizeof(std::shared_ptr<int>) << std::endl;  // 输出 16

    // 由于继承的存在，shared_ptr 可能指向基类对象
    std::shared_ptr<Tomato> tomato = std::make_shared<Tomato>(1);

    std::shared_ptr<Fruit> fruit = tomato;
    std::shared_ptr<Vegetable> vegetable = tomato;

    std::cout<<"....";

}
void Observe(std::weak_ptr<int> wptr) {
    if (auto sptr = wptr.lock()) {
        std::cout <<  "count: " << sptr.use_count() << std::endl;

        std::cout << "value: " << *sptr << std::endl;
    } else {
        std::cout << "wptr lock fail" << std::endl;
    }
}
void testWeakPtr()
{
    std::weak_ptr<int> wptr;
    {
        auto sptr = std::make_shared<int>(111);
        wptr = sptr;
        Observe(wptr);  // sptr 指向的资源没被释放，wptr 可以成功提升为 shared_ptr
    }
    Observe(wptr);  // sptr 指向的资源已被释放，wptr 无法提升为 shared_ptr
}
int main()
{
    //testSharePtr();
    testWeakPtr();
}