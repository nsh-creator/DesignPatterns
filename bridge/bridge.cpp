// 桥接模式 

#include<iostream>

using namespace std;

// 定义一个实现的基类，提供接口
class Implement
{
public:
    virtual ~Implement() {}
    virtual void Action() = 0;
};

// 具体实现A
class ConcreteImplementA : public Implement
{
public:
    ~ConcreteImplementA() {}

    void Action() override {
        cout << "This is ConcreteImplementA !" << endl;
    }
};

// 具体实现B
class ConcreteImplementB : public Implement
{
public:
    ~ConcreteImplementB() {}

    void Action() override {
        cout << "This is ConcreteImplementB !" << endl;
    }
};

// 抽象类基类，提供接口
class Abstract
{
public:

    Abstract() {
        implement = nullptr;
    }

    virtual void Operator() = 0; 

    void SetImplement(Implement *impl) {
        if (implement != nullptr) {
            delete implement;
        }
        implement = impl;
    }

    virtual ~Abstract() {
        if (implement != nullptr) {
            delete implement;
        }
    }
protected:
    Implement *implement;
};

// 扩充抽象类
class RefinedAbstractA : public Abstract
{
public:
    RefinedAbstractA(Implement *impl) 
    {
        implement = impl;
    }

    RefinedAbstractA() {
        implement = nullptr;
    }

    void Operator() override {
        cout << "This is RefinedAbstract. ";
        if (implement != nullptr) {
            implement->Action();
        }
    }
};


// 客户端实现
int main() {
    Abstract* myAbstract = new RefinedAbstractA(new ConcreteImplementA);
    myAbstract->Operator();
    myAbstract->SetImplement(new ConcreteImplementB);
    myAbstract->Operator();
    delete myAbstract;
}