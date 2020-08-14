//
//  main.cpp
//  10cpp对c的扩展
//
//  Created by codew on 8/12/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>
#include "MyCpp01.h"
void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);

using namespace std;

/**
 自定义 命名空间
 */

namespace MyA {

int a = 19;
    namespace MyA1 {

    int a = 404;

    }
}
/**
 后面还可以增加
 */
namespace MyA {

    void fun(){
        cout << "吃饭了没" <<endl;
    }

    void fun(int x){
        cout << "吃饭了没一个x " << x <<endl;
    }

    void fun(int x, int y){
        cout << "吃饭了没" << " x:" << x << " y:" <<y <<endl;
    }
}

namespace MyB {

int a = 9;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test4();
    return 0;
}

/**
 :: 作用域运算符
 */
int a = 10;
void test1(void)
{
    int a = 101;
    
    cout << "局部变量a: " << a <<endl;
    cout << "全局变量a: " << ::a <<endl;
}

/**
 打印自定义命名空间
 */
void test2(void)
{
    cout << "MyA命名空间里变量a: " << MyA::a <<endl;
    cout << "MyB命名空间里变量a: " << MyB::a <<endl;
    
}

/**
 打印嵌套
 */
void test3(void)
{
    cout << "MyA命名空间里的MyA1命名空间 变量a: " << MyA::MyA1::a <<endl;
    
    MyA::fun();
    
}


/**
 打印分离文件
 */
void test4(void)
{
    cout << MyN1::an1 <<endl;
    MyN1::func1();
    
}
void MyN1::func1()
{
    cout << "你瞅啥, 滚一边去!" <<endl;
}
