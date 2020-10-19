//
//  main.cpp
//  96异常变量生命周期
//
//  Created by codew on 10/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

/**
 throw的异常是有类型的，可以是数字、字符串、类对象。

 throw的异常是有类型的，catch需严格匹配异常类型。
 */

using namespace std;

class MyException
{
public:
    MyException()
    {
        cout << "异常变量构造" << endl;
    }
    MyException(const MyException &e)
    {
        cout << "拷贝构造" << endl;
    }
    
    ~MyException()
    {
        cout << "异常变量 析构" << endl;
    }
    
    
};


void doWork()
{
//    throw MyException(); // test1 2 都用
    throw new MyException(); // test3 用
}

void test01()
{
    /**
     异常变量构造
     拷贝构造
     捕获 异常
     异常变量 析构
     异常变量 析构
     */
    try {
        doWork();
    } catch (MyException e) {
        cout << "捕获 异常" << endl;
    }
}

void test02()
{
    /**
     异常变量构造
     捕获 异常
     异常变量 析构
     */
    try {
        doWork();
    } catch (MyException &e) {
        
        cout << "捕获 异常" << endl;
    }
}

void test03()
{
    /**
     异常变量构造
     捕获 异常
     异常变量 析构
     
     必须要删掉, 不然就不发释放
     delete e;
     */
    try {
        doWork();
    } catch (MyException *e) {
        
        cout << "捕获 异常" << endl;
        
        delete e;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test03();
    return 0;
}
