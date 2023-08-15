//
// Created by sc on 2023/5/18.
//
#include "string"
#include "iostream"
#include "thread"
#include "mutex"
class Singleton
{

protected:
    std::string value_;
    Singleton(const std::string value): value_(value)
    {
    }

    static Singleton* singleton_;
    static std::mutex mutex_;

public:
    Singleton(Singleton &other) = delete;

    void operator=(const Singleton &) = delete;


    static Singleton* GetInstance(const std::string& value);

    std::string value() const
    {
        return value_;
    }
};

Singleton* Singleton::singleton_ = nullptr;
std::mutex Singleton::mutex_;


Singleton* Singleton::GetInstance(const std::string &value)
{
    std::lock_guard<std::mutex> lock(mutex_);
    if(singleton_ == nullptr)
    {
        singleton_ = new Singleton(value);
    }
    return singleton_;
}

void ThreadFoo()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("Foo");
    std::cout<< singleton->value() <<std::endl;
}

void ThreadBar()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton* singleton = Singleton::GetInstance("Bar");
    std::cout<< singleton->value() <<std::endl;
}

int main()
{
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;

}