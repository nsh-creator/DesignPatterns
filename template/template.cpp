// 模板模式
#include<iostream>
using namespace std;

class Template
{
public:
    virtual ~Template(){};

    void run() {
        step1();
        step2();
        step3();
    }
protected:
    void step1() {
        cout << "This is Templates step1" << endl;
    }

    virtual void step2() = 0;

    void step3() {
        cout << "This is Templates step3" << endl;
    }
};

class Cilent : public Template
{
protected:
    void step2() {
        cout << "This is Cilent step2" << endl;
    }
};

int main() {
    Template* ptr = new Cilent;
    ptr->run();
    delete ptr;
    return 0;
}