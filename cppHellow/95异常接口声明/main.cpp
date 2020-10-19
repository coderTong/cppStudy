//
//  main.cpp
//  95异常接口声明
//
//  Created by codew on 10/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 为了加强程序的可读性，可以在函数声明中列出可能抛出异常的所有类型，例如：void func() throw(A,B,C);这个函数func能够且只能抛出类型A,B,C及其子类型的异常。

 如果在函数声明中没有包含异常接口声明，则此函数可以抛任何类型的异常，例如:void func()

 一个不抛任何类型异常的函数可声明为:void func() throw()

 如果一个函数抛出了它的异常接口声明所不允许抛出的异常,unexcepted函数会被调用，该函数默认行为调用terminate函数中断程序。
 */

// 可抛出 所有 类型异常

void TestFunction01()
{
    throw 10;
}

// 只能抛出 int char char* 类型异常
void TestFunction02() throw(int, char, char*)
{
    // 抛出其他异常就报错
//    string exception = "error!";
//    throw exception;
    
    // 可以正常抛出
    throw 10;
}
//不能抛出任何类型异常
void TestFunction03() throw()
{
    throw 10;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    try {
        
//        TestFunction01();
//        TestFunction02();
        TestFunction03();
    } catch (...) {
        
        cout << "捕获异常" << endl;
    }
    
    return 0;
}
