//
//  main.cpp
//  92异常基本语法
//
//  Created by codew on 10/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

int A_MyDivide(int a, int b)
{
    if (b == 0) {
        
        throw 9;
    }
    return a / b;
}

//B写的代码 B写代码比较粗心，忘记处理异常
int B_MyDivide(int a, int b)
{
    int ba = a;
    int bb = b;
    
    int ret = A_MyDivide(a, b) + 100; //由于B没有处理异常，导致B结果运算错误
    
    return ret;
}

//C写的代码
int C_MyDivide()
{
    int a = 10;
    int b = 0;
    
    int ret = 0;
    
// 没有 处理 异常, 程序直接 中断执行
#if 0
    ret = B_MyDivide(a, b);
   
#else
// 处理异常
    try {
        ret = A_MyDivide(a, b);
    } catch (int e) {
        
        cout << "C_MyDivide Call A_MyDivide 异常: " << e << endl;
    }
    
#endif
    
    return  ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    C_MyDivide();
    
    return 0;
}
