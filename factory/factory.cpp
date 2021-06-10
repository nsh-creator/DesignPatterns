// 工厂模式

#include<iostream>
using namespace std;

enum PRODUCT_TYPE
{
  PRODUCTA,
  PRODUCTB,
  PRODUCT_NUM
};
// 产品基类
class Product
{
public:
  Product() {};
  virtual ~Product() {};
  virtual void Function() = 0;
};

// 具体产品A
class ConctreteProductA : public Product
{
public:
  ConctreteProductA() {};
  ~ConctreteProductA() {};
  void Function() override
  {
    cout << "This is ConctreteProductA" << endl;
  }
};

// 具体产品B
class ConctreteProductB : public Product
{
public:
  ConctreteProductB() {};
  ~ConctreteProductB() {};
  void Function() override
  {
    cout << "This is ConctreteProductB" << endl;
  }
};

// 基类工厂
class Factory
{
public:
  Factory() {};
  virtual ~Factory() {};
  virtual Product *CreateProduct(PRODUCT_TYPE ProductType) = 0;
  virtual Product *CreateProductA() = 0;
  virtual Product *CreateProductB() = 0;
};

// 具体工厂
class ConctreteFactory : public Factory
{
public:
  ConctreteFactory() {};
  ~ConctreteFactory() {};
  Product *CreateProduct(PRODUCT_TYPE ProductType) {
    Product* p = nullptr;
    switch (ProductType)
    {
    case PRODUCTA:
      p = new ConctreteProductA;
      break;
    case PRODUCTB:
      p = new ConctreteProductB;
      break;
    default:
      p = nullptr;
      break;
    }
    return p;
  }

  Product* CreateProductA() {
    return new ConctreteProductA;
  };

  Product* CreateProductB() {
    return new ConctreteProductB;
  };
};

// 客户端测试
int main() {
  ConctreteFactory *MyFactory = new ConctreteFactory;

  Product *MyProductA = MyFactory->CreateProduct(PRODUCTA);
  MyProductA->Function();
  delete MyProductA;
  MyProductA = MyFactory->CreateProductA();
  MyProductA->Function();
  delete MyProductA;

  Product *MyProductB = MyFactory->CreateProduct(PRODUCTB);
  MyProductB->Function();
  delete MyProductB;
  MyProductB = MyFactory->CreateProductB();
  MyProductB->Function();
  delete MyProductB;

  delete MyFactory;
  return 0;
}