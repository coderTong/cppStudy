//
//  main.cpp
//  12cppConst
//
//  Created by codew on 8/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>


#define PARAM 1
const  short  param = 128;

using namespace std;

namespace  MySpace{

 #define num 1024

}


void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);


void  func(short a);
void  func(int a);

void test();
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    test();

//    func(param);
    
    return 0;
}

void test1(void)
{
    const  int  constA = 10;

    int* p = (int*)&constA;

    *p = 300;

    cout << "constA:" << constA << endl;

    cout << "*p:" << *p << endl;
}

/**
 用一个普通变量去初始化它
 */
void test2(void)
{

    int b = 10;

    const  int  constA = b;

    int* p = (int*)&constA;

    *p = 300;
    
    cout << "b:" << b << endl;

    cout << "constA:" << constA << endl;

    cout << "*p:" << *p << endl;
}







void  func(short a){

 cout << "short!" << endl;

}

void  func(int a){

 cout << "int" << endl;

}


void test(){

//  cout << MySpace::num << endl; //错误

//  int num = 100; //命名冲突

 cout << num << endl;

}
