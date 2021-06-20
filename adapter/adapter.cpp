// 适配器模式

#include<iostream>

using namespace std;

class Target
{
public:
    virtual ~Target() {}
    virtual void Function() = 0;
};


class Adaptee
{
public:
    void ConcreteFunction() {
        cout << "This is Adaptee ConcreteFunction!" << endl;
    }
};

class Adapter : public Target
{
public:
    Adapter() : adaptee() {}
    void Function() override {
        adaptee->ConcreteFunction();
    }
private:
    Adaptee* adaptee; 
};


int main() {
    Target* myTarget = new Adapter();
    myTarget->Function();
    delete myTarget;
    return 0;
}