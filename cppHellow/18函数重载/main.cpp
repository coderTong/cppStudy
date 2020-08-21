//
//  main.cpp
//  18函数重载
//
//  Created by codew on 8/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

//1\. 函数重载条件

namespace  A{

 void MyFunc(){ cout << "无参数!" << endl; }

 void MyFunc(int a){ cout << "a: " << a << endl; }

 void MyFunc(string b){ cout << "b: " << b << endl; }

 void MyFunc(int a, string b){ cout << "a: " << a << " b:" << b << endl;}

 void MyFunc(string b, int a){cout << "a: " << a << " b:" << b << endl;}

}

//2.返回值不作为函数重载依据

namespace  B{

 void MyFunc(string b, int a){}

// int MyFunc(string b, int a){} //无法重载仅按返回值区分的函数

}

//这时，两个函数都能匹配调用，产生二义性
void MyFunc(string b){

 cout << "b: " << b << endl;

}

//这时，两个函数都能匹配调用，产生二义性
//函数重载碰上默认参数
void MyFunc(string b, int a = 10){

 cout << "a: " << a << " b:" << b << endl;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
//    MyFunc("hello"); //这时，两个函数都能匹配调用，产生二义性
    
    
    return 0;
}
