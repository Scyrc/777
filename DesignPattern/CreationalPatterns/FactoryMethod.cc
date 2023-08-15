//
// Created by sc on 2023/5/18.
//
#include "string"
#include "iostream"
class Product
{
public:
    virtual ~Product(){}
    virtual std::string Operation() const = 0;
};


class Product1 : public Product
{
public:
    std::string Operation() const override
    {
        return "{Product1}";
    }
};

class Product2 : public Product
{
public:
    std::string Operation() const override
    {
        return "{Product2}";
    }
};

class Creator
{
public:
    virtual Product* FactoryMethod() const = 0;

    std::string SomeWork() const
    {
        Product* product = this->FactoryMethod();
        auto res = product->Operation();
        delete product;
        return res;
    }
};

class Creator1: public Creator
{
public:
    Product* FactoryMethod() const override
    {
        return new Product1;
    }
};

class Creator2: public Creator
{
public:
    Product* FactoryMethod() const override
    {
        return new Product2;
    }
};

int main()
{
    Creator* creator1 = new Creator1();
    std::cout<<creator1->SomeWork();
    std::cout<<std::endl;
    Creator* creator2 = new Creator2();
    std::cout<<creator2->SomeWork();
}