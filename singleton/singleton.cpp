// 实现线程安全的懒汉单例模式

#include<iostream>
#include<mutex>

using namespace std;

class Singleton
{
public:
    // 删除拷贝构造函数与赋值函数防止重复创建
    Singleton(Singleton const &) = delete;
    Singleton& operator=(Singleton const &) = delete;

    void Funciton() {
        cout << "This is a Singleton!" << endl;
    }

    static Singleton* GetInstance() {
        if (instance != nullptr) {
            instance = new Singleton;
        }
        return instance;
    }
    
    static void RestartInstance() {
        if (instance != nullptr) {
            delete instance;
        }
    }

private:
    Singleton() {};
    static Singleton* instance;
};

Singleton* Singleton::instance = nullptr;

int main() {
    Singleton::GetInstance()->Funciton();
    Singleton::RestartInstance();
    return 0;
}