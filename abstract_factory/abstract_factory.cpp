// 抽象工厂类

#include<iostream>
using namespace std;

// 产品A
class ProductA
{
public:
    ProductA() {};
    virtual ~ProductA() {};
    virtual void Function() = 0;
};

class ConctreteProductAX : public ProductA
{
public:
    ConctreteProductAX() {};
    ~ConctreteProductAX() {};
    void Function() {
        cout << "This is Product A-X" << endl;
    }
};

class ConctreteProductAY : public ProductA
{
public:
    ConctreteProductAY() {};
    ~ConctreteProductAY() {};
    void Function() {
        cout << "This is Product A-Y" << endl;
    }
};

// 产品B
class ProductB
{
public:
    ProductB() {};
    virtual ~ProductB() {};
    virtual void Function() = 0;
};

class ConctreteProductBX : public ProductB
{
public:
    ConctreteProductBX() {};
    ~ConctreteProductBX() {};
    void Function() {
        cout << "This is Product B-X" << endl;
    }
};

class ConctreteProductBY : public ProductB
{
public:
    ConctreteProductBY() {};
    ~ConctreteProductBY() {};
    void Function() {
        cout << "This is Product B-Y" << endl;
    }
};

// 工厂类
class AbstractFactory
{
public:
    AbstractFactory() {};
    virtual ~AbstractFactory() {};
    virtual ProductA *CreateProductA() = 0;
    virtual ProductB *CreateProductB() = 0;
};

class ConctreteFactoryX : public AbstractFactory
{
public:
    ConctreteFactoryX() {};
    virtual ~ConctreteFactoryX() {};
    ProductA *CreateProductA() override {
        return new ConctreteProductAX;
    }
    ProductB *CreateProductB() override {
        return new ConctreteProductBX;
    }
};

class ConctreteFactoryY : public AbstractFactory
{
public:
    ConctreteFactoryY() {};
    virtual ~ConctreteFactoryY() {};
    ProductA *CreateProductA() override {
        return new ConctreteProductAY;
    }
    ProductB *CreateProductB() override {
        return new ConctreteProductBY;
    }
};


// 客户端测试
int main() {
    AbstractFactory *MyFactoryX = new ConctreteFactoryX;

    ProductA *MyProductA = MyFactoryX->CreateProductA();
    MyProductA->Function();
    delete MyProductA;
    ProductB *MyProductB = MyFactoryX->CreateProductB();
    MyProductB->Function();
    delete MyProductB;

    delete MyFactoryX;

    AbstractFactory *MyFactoryY = new ConctreteFactoryY;

    MyProductA = MyFactoryY->CreateProductA();
    MyProductA->Function();
    delete MyProductA;
    MyProductB = MyFactoryY->CreateProductB();
    MyProductB->Function();
    delete MyProductB;

    delete MyFactoryY;
}