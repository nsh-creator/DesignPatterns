// 构造者模式

// 构造者模式是用于构建和其表示分离

#include<iostream>
using namespace std;

class Product
{
public:
    Product() {};
    void MakeProductA(string ProductA) {
        this->ProductA = ProductA;
    }

    void MakeProductB(string ProductB) {
        this->ProductB = ProductB;
    }

    void ShowProduct() {
        cout << "ProductA: " << this->ProductA << "    ";
        cout << "ProductB: " << this->ProductB << endl;
    }
private:
    string ProductA;
    string ProductB;
};

// 构建者基类
class Builder
{
public:
    Builder() {
        CurrentProduct = new Product;
    };
    virtual ~Builder() {
        delete CurrentProduct;
    };
    virtual void BuildProductA() = 0;
    virtual void BuildProductB() = 0;
    Product *GetProduct() {
        return CurrentProduct;
    }
protected:
    Product *CurrentProduct;
};

// 具体的构建类X
class ConctreteBuilderX : public Builder
{
    void BuildProductA() override {
        CurrentProduct->MakeProductA("Product A-X");
    }

    void BuildProductB() override {
        CurrentProduct->MakeProductB("Product B-X");
    }
};

// 具体的构建类Y
class ConctreteBuilderY : public Builder
{
    void BuildProductA() override {
        CurrentProduct->MakeProductA("Product A-Y");
    }

    void BuildProductB() override {
        CurrentProduct->MakeProductB("Product B-Y");
    }
};


// 管理类
class Director
{
public:
    Director() {
        CurrentBuilder = nullptr;
    }

    Director(Builder* Builder) {
        CurrentBuilder = Builder;
    }

    ~Director() {
        if (CurrentBuilder != nullptr) {
            delete CurrentBuilder;
        } 
    }

    void SetBuilder(Builder* Builder) {
        if (CurrentBuilder != nullptr) {
            delete CurrentBuilder;
        }
        CurrentBuilder = Builder;
    }

    Product* GetProduct() {
        return CurrentBuilder->GetProduct();
    }

    void Construct() {
        if (CurrentBuilder == nullptr) {
            return;
        }
        CurrentBuilder->BuildProductA();
        CurrentBuilder->BuildProductB();
    }

private:
    Builder* CurrentBuilder;
};

int main() {
    Director *MyDirector = new Director(new ConctreteBuilderX);
    MyDirector->Construct();
    Product *MyProduct = MyDirector->GetProduct();
    MyProduct->ShowProduct();
    MyDirector->SetBuilder(new ConctreteBuilderY);
    MyDirector->Construct();
    MyProduct = MyDirector->GetProduct();
    MyProduct->ShowProduct();
    delete MyDirector;
    system("pause");
    return 0;
}