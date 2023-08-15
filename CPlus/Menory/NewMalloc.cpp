
#include <iostream>
class MyClass
{
public:
    explicit MyClass(int value):value_(value){}

    void doSomething(){ std::cout<<"do something " <<value_ <<std::endl;}
private:
    int value_;
};
void newTest()
{
    int *a = new int(1);
    delete a;

    int *c = new int[11];
    delete [] c;

    try {
        MyClass* myClass = new MyClass(1);
        myClass->doSomething();

    }
    catch (std::bad_alloc){

    }
}
void placementNewTestHeap()
{
    int *a = new int[10];
    int* b = a;
    int* c = a;
    for(int i=0;i<10;++i)
    {
        *a = i;
        ++a;
    }



    int* d = new (c) int[10];
    for(int i=0;i<10;++i)
    {
        *d = i+2;
        ++d;
    }
    for(int i=0;i<10;++i)
    {
        std::cout<<*b<<" ";
        ++b;
    }
    std::cout<<std::endl;
 /*   for(int i=0;i<10;++i)
    {
        std::cout<<*c<<" ";
        ++c;
    }*/
}
void placementNewTestStack()
{
    int a[10]{1,2,3,4,5,6,7,8,9,10};
    int* d = new (&a) int[10];
    for(int i=0;i<10;++i)
    {
        *d = 10-i;
        ++d;
    }
    for(auto&& x : a)
    {
        std::cout<< x << " ";
    }

}


int main()
{
    //newTest();
    placementNewTestHeap();
    placementNewTestStack();
}
