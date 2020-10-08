//
//  main.cpp
//  82类模板派生类模板
//
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

// 父类 类模板

template <class T>
class BaseClass
{
    T m;
};

template<class T>
class ChildClass2 : public BaseClass<double> // 继承 类模板 的 时候, 必须 要确定基类的大小
{
public:
    T mParam;
};

void test02
{
    ChildClass2<int> d2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
