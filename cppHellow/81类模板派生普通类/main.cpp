//
//  main.cpp
//  81类模板派生普通类
// 2020年10月05日22:02:52
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

// 类模板
template <class T>
class Myclass {
    
public:
    Myclass(T property)
    {
        this->property = property;
    }
    
public:
    T property;
};

// 子类 实例化 的 时候 需要具体化的父类, 子类需要 知道父类的具体 类型 是 什么样 的
// 这样 c++编译器 才能 知道 给 子类 分配 多少内存

// 普通派生类
class SubClass : public Myclass<int>
{
public:
    SubClass(int b) : Myclass <int>(20)
    {
        this->mB = b;
    }
    
public:
    int mB;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
