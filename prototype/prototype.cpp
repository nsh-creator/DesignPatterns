// 原型模式


#include<iostream>
using namespace std;


enum PROTOTYPE
{
    PROTOTYPE_A,
    PROTOTYPE_B,
    PROTOTYPE_NUM
};

// 原型接口
class ProtoType
{
public:
    ProtoType() {}

    ProtoType(string name) {
        this->name = name;
    }

    virtual ~ProtoType() {}

    void SetName(string name) {
        this->name = name;
    }

    virtual ProtoType* Clone() = 0;
    virtual void ShowType() = 0; 

    void ShowName() {
        cout << "The instance name is " << name << endl;
    }

protected:
    string name;
};

// 定义具体原型A
class ConcreteProtoTypeA : public ProtoType
{
public:
    ConcreteProtoTypeA() {};
    ConcreteProtoTypeA(string name) : ProtoType(name) {};

    void ShowType() override {
        cout << "This Type is ConcreteProtoTypeA!" << endl;
    }

    ProtoType* Clone() override {
        ProtoType* pA = new ConcreteProtoTypeA();
        *pA = *this;
        return pA;
    }
};

// 定义具体原型B
class ConcreteProtoTypeB : public ProtoType
{
public:
    ConcreteProtoTypeB() {};
    ConcreteProtoTypeB(string name) : ProtoType(name) {};

    void ShowType() override {
        cout << "This Type is ConcreteProtoTypeB!" << endl;
    }

    ProtoType* Clone() override {
        ProtoType* pB = new ConcreteProtoTypeB();
        *pB = *this;
        return pB;
    }
};

class Client
{
public:
    static void Init() {
        protoTypeArray = new ProtoType*[PROTOTYPE_NUM];
        protoTypeArray[PROTOTYPE_A] = new ConcreteProtoTypeA("Name-A");
        protoTypeArray[PROTOTYPE_B] = new ConcreteProtoTypeB("Name-B");
    }

    static ProtoType* CopyProtoType(PROTOTYPE prototype) {
        return protoTypeArray[prototype]->Clone();
    }

    static void Restart() {
        delete protoTypeArray[PROTOTYPE_A];
        delete protoTypeArray[PROTOTYPE_B];
        delete [] protoTypeArray;
        protoTypeArray = nullptr;
    }

    static ProtoType** protoTypeArray;
};

ProtoType** Client::protoTypeArray = nullptr;

int main() {
    Client::Init();

    ProtoType* myProtoTypeA = Client::CopyProtoType(PROTOTYPE_A);
    myProtoTypeA->ShowName();
    myProtoTypeA->ShowType();
    myProtoTypeA->SetName("New-Name-A");
    myProtoTypeA->ShowName();
    Client::protoTypeArray[PROTOTYPE_A]->ShowName();
    delete myProtoTypeA;

    ProtoType* myProtoTypeB = Client::CopyProtoType(PROTOTYPE_B);
    myProtoTypeB->ShowName();
    myProtoTypeB->ShowType();
    myProtoTypeB->SetName("New-Name-B");
    myProtoTypeB->ShowName();
    Client::protoTypeArray[PROTOTYPE_B]->ShowName();
    delete myProtoTypeB;

}