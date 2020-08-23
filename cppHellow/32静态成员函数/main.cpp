//
//  main.cpp
//  32静态成员函数
//
//  Created by codew on 8/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person{
  
public:
    // 普通成员函数可以访问static和non-static 成员属性
    void change1Param(int param)
    {
        printf("%s\n", __func__);
        mParam = param;
        sNum = param;
    }
    // 静态成员函数只能访问 static 成员属性
    static void change2Static(int param){
        printf("%s\n", __func__);
//        mParam = param; // 不能访问错误
        sNum = param;
    }
    
private:
    static void change3Static2PR(int param){
            printf("%s\n", __func__);
//            mParam = param; // 不能访问错误
            sNum = param;
        }
    
public:
    int mParam;
    static int sNum;
};

// 在类外 初始化 静态成员属性

int Person::sNum = 0;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    // 1. 类名直接调用
    Person::change2Static(100);
    
    // 2. 通过对象调用
    Person p;
    p.change2Static(200);
    
    // 3. 静态成员函数也有访问权限
    // 类外无法访问 私有静态成员函数
//    Person::change3Static2PR(100);
    Person p1;
    // 无法访问
//    p1.change3Static2PR(22);
    
    return 0;
}
