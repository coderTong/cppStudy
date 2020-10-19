//
//  main.cpp
//  90常量转换
//
//  Created by codew on 10/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

void test01()
{
    const int* p = NULL;
    int* np = const_cast<int *>(p);
    
    int* pp  = NULL;
    const int* npp = const_cast<const int*>(pp);
    
    const int a = 10; // 不能对非指针 或 非 引用进行 转换
    int b = const_cast<int>(a);
    
    
}


void test02()
{
    int num = 10;
    int & refNum = num;
    
    const int& refNum2 = const_cast<const int&>(refNum);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
