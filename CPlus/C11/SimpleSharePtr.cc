//
// Created by sc on 2023/5/20.
//


#include <iostream>

template<typename T>
class SimpleSharePtr
{
private:
    T* ptr_;
    size_t* count_;
    void release()
    {
        if(count_ == nullptr) return;
        if(--(*count_) == 0)
        {
            delete ptr_;
            ptr_ = nullptr;
            delete count_;
        }
        count_ = nullptr;
    }
public:
    // 构造
    explicit SimpleSharePtr(T* ptr):ptr_(ptr), count_(ptr ? new size_t(1) : nullptr){}

    // copy 构造
    SimpleSharePtr(const SimpleSharePtr& other):ptr_(other.ptr_), count_(other.count_)
    {
        if(count_)
        {
            ++(*count_);
        }
    }
    // 移动 构造
    SimpleSharePtr(const SimpleSharePtr&& other) noexcept
    :ptr_(other.ptr_),
    count_(other.count_)
    {
        other.ptr_ = nullptr;
        other.count_ = nullptr;
    }

    // =
    SimpleSharePtr& operator=(const SimpleSharePtr& other)
    {
        if(this != other)
        {
            release();
            ptr_ = other.ptr_;
            count_ = other.count_;
            if(count_)  ++(*count_);
        }
        return *this;
    }

    SimpleSharePtr& operator=(SimpleSharePtr&& other) noexcept
    {
        if(this != other)
        {
            release();
            ptr_ = other.ptr_;
            count_ = other.count_;

            other.ptr_ = nullptr;
            other.count_ = nullptr;
        }
        return *this;
    }

    ~SimpleSharePtr(){ release();}

    T& operator*() const {return *ptr_;}
    T* operator-> () const {return ptr_;}
    T* get() const{ return ptr_;}
    size_t use_count() const {return count_ ? *count_ : 0;}
};

class MyClass{
public:
    MyClass(){std::cout<<"MyClass creat\n";}
    ~MyClass(){std::cout<<"MyClass delete\n";}
    void do_something() { std::cout << "MyClass::do_something()\n"; }
};
int main()
{
    {
        SimpleSharePtr<MyClass> ptr1(new MyClass());
        {
            SimpleSharePtr<MyClass> ptr2 = ptr1;
            ptr1->do_something();
            ptr2->do_something();
            std::cout << "use_count: " << ptr1.use_count() << std::endl;
        }
        std::cout << "use_count: " << ptr1.use_count() << std::endl;
    }

    return 0;
}