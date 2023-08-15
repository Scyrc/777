//
// Created by sc on 2023/5/18.
//
#include <iostream>
#include <string>
using std::string;
class AbstractProductA
{
public:
    virtual ~AbstractProductA(){}
    virtual string UsefulFunA() const =0;
};

class ProductA1: public AbstractProductA
{
public:
    ~ProductA1(){}
    string UsefulFunA() const override
    {
        return "ProductA1 Called";
    }
};


class ProductA2: public AbstractProductA
{
public:
    ~ProductA2(){}
    string UsefulFunA() const override
    {
        return "ProductA2 Called";
    }
};

class AbstractProductB
{
public:
    virtual ~AbstractProductB(){}
    virtual string UsefulFunB() const =0;
    virtual string AnotherUsefulFunB(const AbstractProductA &collaborator) const = 0;
};

class ProductB1: public AbstractProductB
{
public:
    ~ProductB1(){}
    string UsefulFunB() const override
    {
        return "ProductB1 Called";
    }
    string AnotherUsefulFunB(const AbstractProductA &collaborator) const override
    {
        const std::string result = collaborator.UsefulFunA();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};


class ProductB2: public AbstractProductB
{
public:
    ~ProductB2(){}
    string UsefulFunB() const override
    {
        return "ProductB2 Called";
    }
    string AnotherUsefulFunB(const AbstractProductA &collaborator) const override
    {
        const std::string result = collaborator.UsefulFunA();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};

class AbstractFactory
{
public:
    virtual AbstractProductA* CreateProductA() const =0;
    virtual AbstractProductB* CreateProductB() const =0;
};

class Factory1 : public AbstractFactory
{
    virtual AbstractProductA* CreateProductA() const override
    {
        return new ProductA1();
    }
    virtual AbstractProductB* CreateProductB() const override
    {
        return new ProductB1();
    }
};

class Factory2 : public AbstractFactory
{
    virtual AbstractProductA* CreateProductA() const override
    {
        return new ProductA2();
    }
    virtual AbstractProductB* CreateProductB() const override
    {
        return new ProductB2();
    }
};

void ClientNode(AbstractFactory* Factory)
{
    const AbstractProductA* ProductA = Factory->CreateProductA();
    const AbstractProductB* ProductB = Factory->CreateProductB();
    std::cout << ProductB->UsefulFunB() << "\n";
    std::cout << ProductB->AnotherUsefulFunB(*ProductA) << "\n";
    delete ProductA;
    delete ProductB;
}

int main()
{
    Factory1* f1  = new Factory1();
    ClientNode(f1);
    delete f1;
    std::cout<<std::endl;

    Factory2* f2  = new Factory2();
    ClientNode(f2);
    delete f2;
}