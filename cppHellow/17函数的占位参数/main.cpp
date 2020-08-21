//
//  main.cpp
//  17函数的占位参数
//
//  Created by codew on 8/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>


void  TestFunc01(int a,int b,int){

  //函数内部无法使用占位参数
 cout << "a + b = " << a + b << endl;

}

//占位参数也可以设置默认值

void TestFunc02(int a, int b, int = 20){

  //函数内部依旧无法使用占位参数
 cout << "a + b = " << a + b << endl;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
