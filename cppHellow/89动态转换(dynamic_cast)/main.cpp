//
//  main.cpp
//  89动态转换(dynamic_cast)
//
//  Created by codew on 10/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Animal
{
public:
    virtual void showName() = 0;
};

class Dog : public Animal
{
    virtual void showName()
    {
        cout << "dog dog go go" << endl;
    }
};

class Other{
    
public:
    void showInfo()
    {
        cout << "你瞅啥!" << endl;
    }
};

// 普通类型 转换
void test01()
{
    // 不支持 基础数据 类型
    int a = 10;
//    double a = dynamic_cast<double>(a);
}

void test02()
{
    Animal * animal01 = NULL;
    Dog * dog01 = new Dog;
    
    // 子类 指针 转换 成 父类 指针 可以
    Animal * animal02 = dynamic_cast<Animal*>(dog01);
    animal02->showName();
    
    // 父类 指针 转换 成 子类 指针, 不可以
    Dog * dog02 = dynamic_cast<Dog*>(animal01);
//    dog02->showName();
}

void test03()
{
    Dog dog_ref;
    Dog& dog01 = dog_ref;
    
    // 子类引用 转换成 父类 引用 --->可以
    Animal & animal02 = dynamic_cast<Animal&>(dog01);
    animal02.showName();
    
}

void test04()
{
    Animal* animal01 = NULL;
    Other * other = NULL;
    
    // 不可以
//    Animal * animal02 = dynamic_cast<Animal *>(other);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test03();
    return 0;
}
