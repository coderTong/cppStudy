//
//  main.cpp
//  27explicit关键字
//
//  Created by codew on 8/22/20.
//  Copyright © 2020 codertom. All rights reserved.
/**
 
 ADD: 2020年10月19日10:49:56
 C++提供了关键字explicit，禁止通过构造函数进行的隐式转换。声明为explicit的构造函数不能在隐式转换中使用。
 */

#include <iostream>

using namespace std;

class MyString {
    
    
public:
    explicit MyString(int n){
        
        cout << "MyString(int n)" << endl;
    }
    
    MyString(const char * str){
        
        cout << "MyString(const char * str)" <<endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    //给字符串赋值？还是初始化？

//     MyString str1 = 1;

    MyString str2(10);

     //寓意非常明确，给字符串赋值

    MyString str3 = "abcd";

    MyString str4("abcd");

    
    
    return 0;
}
