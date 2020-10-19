//
//  main.cpp
//  86模板类碰到友元函数
//
//  Created by codew on 10/18/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

template<class T1, class T2> class Person;
// 告诉 编译器 这个函数 模板是存在
template<class T1, class T2>void PrintPerson2(Person<T1, T2>& p);

// 友元函数在 类 内 实现
template <class T1, class T2>
class Person{
    
    // 1. 友元函数 在类的内部 实现
    friend void PrintPerson(Person<T1, T2>& p){
        
        cout<< "Name: " << p.mName << " Age:" << p.mAge << endl;
    }
    
    // 2. 友元  函数 类 外实现
    // 告诉 编译器 这个 函数 模板 是 存在
    /**
     反正这个玩意就是,规矩
     友元函数模板 外面 实现的话 就他妈要加 <>
     2020年10月18日23:10:19
     */
    friend void PrintPerson2<>(Person<T1, T2>& p);
    
    // 3. 类模板 碰到 友元 函数 模板
    template <class U1, class U2>
    friend void PrintPerson(Person<U1, U2>& p);
    
    
  
public:
    Person(T1 name, T2 age){
        
        this->mName = name;
        this->mAge = age;
    }
    
    void showPerson(){
        cout << "name: " << this->mName << " Age:" << this->mAge << endl;
    }
private:
    T1 mName;
    T2 mAge;
};


void test01()
{
    Person<string, int>p("Jerry", 20);
    PrintPerson(p);
}


// 类模板 碰到 友元 函数
// 友元 函数 类外 实现, 加上<> 空参数列表, 告诉 编译 匹配 函数模板
template <class T1, class T2>
void PrintPerson2(Person<T1, T2>& p)
{
    cout << "Name2: "  << p.mName << " Age2:" << p.mAge << endl;
}

void test02()
{
    Person<string, int>p("Tom", 20);
    //不写可以编译通过，写了之后，会找PrintPerson2的普通函数调用，因为写了普通函数PrintPerson2的声明
    PrintPerson2(p);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    test02();

    
    return 0;
}
