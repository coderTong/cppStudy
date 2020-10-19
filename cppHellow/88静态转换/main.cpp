//
//  main.cpp
//  88静态转换
//
//  Created by codew on 10/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Animal{};
class Dog : public Animal{};
class Other{};

void test01()
{
    char a = 'a';
    double b = static_cast<double>(a);
    
    cout << "b :" << b << endl;
}

void test02()
{
    
    Animal * animal01 = NULL;
    Dog *dog1 = NULL;
    
    // 子类 指针 转成 父类 指针, 安全
    Animal * animal02 = static_cast<Animal*>(dog1);
    // 父类指针 转成 子类 指针 , 不安全
    Dog * dog02 = static_cast<Dog *>(animal01);
}

// 继承关系 引用相互转换
void test03()
{
    Animal ani_ref;
    Dog dog_ref;
    
    // 继承关系 指针 转换
    Animal&  animal01 = ani_ref;
    Dog & dog01 = dog_ref;
    
    // 子类指针转成 父类指针 , 安全
    Animal& animal02 = static_cast<Animal&>(dog01);
    
    // 父类 指针 转换 子类 指针 , 不安全
    Dog& dog02 = static_cast<Dog&>(animal01);
}

// 无继承 关系 指针转换
void test04()
{
    Animal * animal01 = NULL;
    Other * other01 = NULL;
    
    // 转换失败
//    Animal * animal02 = static_cast<Animal*>(other01);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test01();
    return 0;
}
