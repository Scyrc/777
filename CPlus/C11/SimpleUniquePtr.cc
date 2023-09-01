//
// Created by sc on 2023/8/31.
//
#include <iostream>
using namespace std;
namespace smartPointer
{
    template<typename T>
    struct MyDeleter
    {
        void operator() (const T* Ptr)
        {
            if(Ptr == nullptr) return;
            delete Ptr;
            Ptr = nullptr;
            cout<< "delete ptr"<<endl;
        }
    };
    template<typename T, typename Deleter = MyDeleter<T>>
    class SimpleUniquePtr
    {
    public:
        explicit SimpleUniquePtr(T* Ptr) : PtrResource(Ptr) {}
        SimpleUniquePtr(SimpleUniquePtr&& other)  noexcept : PtrResource(other.PtrResource)
        {
            other.PtrResource = nullptr;
        }
        ~SimpleUniquePtr() { del();}
        SimpleUniquePtr(const SimpleUniquePtr& other) = delete;
        SimpleUniquePtr& operator= (const SimpleUniquePtr& other) = delete;

        SimpleUniquePtr& operator= (SimpleUniquePtr&& other) noexcept
        {
            std::swap(PtrResource, other.PtrResource);
            return *this;
        }

        void swap(SimpleUniquePtr& p)
        {
            std::swap(PtrResource, p.PtrResource);
        }
        T* get() { return PtrResource;}

        T* release()
        {
            T* tmp = PtrResource;
            PtrResource = nullptr;
            return tmp;
        }

        void reset(T* PtrNew)
        {
            del();
            PtrResource = PtrNew;
        }

        T& operator* ()
        {
            return *PtrResource;
        }

        T* operator-> ()
        {
            return PtrResource;
        }
    private:
        void del()
        {
           Deleter()(PtrResource);
        }
    private:
        T* PtrResource;
    };
}


int main()
{
    smartPointer::SimpleUniquePtr<int> uniquePtr(new int(1));
    uniquePtr.reset(new int(10));
    smartPointer::SimpleUniquePtr<int> uniquePtr1(new int(2));
    uniquePtr.swap(uniquePtr1);
    uniquePtr =  smartPointer::SimpleUniquePtr<int>(new int(3));
    //smartPointer::SimpleUniquePtr<int> uniquePtr2 = uniquePtr1;

    smartPointer::SimpleUniquePtr<int> uniquePtr2 = std::move(uniquePtr1);
    uniquePtr2.release();
    if(uniquePtr.get() != nullptr)
        cout<< "uniquePtr " <<*uniquePtr<<endl;
    if(uniquePtr1.get() != nullptr)
        cout<< "uniquePtr1 " <<*uniquePtr1<<endl;
    if(uniquePtr2.get() != nullptr)
        cout<< "uniquePtr2 " <<*uniquePtr2<<endl;

    return 0;
}