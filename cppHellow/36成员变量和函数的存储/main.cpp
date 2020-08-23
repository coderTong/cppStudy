//
//  main.cpp
//  36成员变量和函数的存储
//
//  Created by codew on 8/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>


/**
 
 在c语言中， 变量和函数“分开来声明的，也就是说，语言本身并没有支持“数据”和“函数”之间的关联性我们把这种程序方法称为“程序性的”，由一组“分布在各个以功能为导航的函数中”的算法驱动，它们处理的是共同的外部数据。

 c++实现了“封装”，那么数据(成员属性)和操作(成员函数)是什么样的呢？

 “数据”和“处理数据的操作(函数)”是分开存储的。

 c++中的非静态数据成员直接内含在类对象中，就像c struct一样。

 成员函数(member function)虽然内含在class声明之内，却不出现在对象中。

 每一个非内联成员函数(non-inline member function)只会诞生一份函数实例.
 
 */

using namespace std;

class MyClass01 {
    
public:
    int mA;
    int mB;
};

class MyClass02 {
    
public:
    int mA;
    static int sB;
};


class MyClass03 {
    
public:
    void printMyClass(){
        
        cout << "hello world!" <<endl;
    }
    
    
public:
    int mA;
    static int sB;
};


class MyClass04 {
    
public:
    void printMyClass(){
        
        cout << "hello world!" <<__func__ <<endl;
    }
    
    static void showMyClass(){
        
        cout << "hello world!" <<__func__ <<endl;
    }
    
    
public:
    int mA;
    static int sB;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    MyClass01 mClass01;
    MyClass02 mClass02;
    MyClass03 mClass03;
    MyClass04 mClass04;
    
    cout << "MyClass01:" << sizeof(mClass01) << endl; //4
    
    //静态数据成员并不保存在类对象中
    cout << "MyClass02:" << sizeof(mClass02) << endl; //4

    //非静态成员函数不保存在类对象中
    cout << "MyClass03:" << sizeof(mClass03) << endl; //4

    //静态成员函数也不保存在类对象中
    cout << "MyClass04:" << sizeof(mClass04) << endl; //4
    
    
    return 0;
}
