//
//  main.cpp
//  31静态成员变量01
//
//  Created by codew on 8/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person{
  
public:
    // 类的 静态成员
    static int sNum;
private:
    static int sOther;
};

// 要在类外初始化, 初始化时不加 static
int Person::sNum = 26;
int Person::sOther = 24;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    // 1. 通过类名直接访问
    Person::sNum = 1000;
    
    cout << "Person::sNum:" << Person::sNum << endl;
    // 私有不能访问
//    cout << "Person::sOther:" << Person::sOther << endl;
    
    
    Person p1, p2;
    p1.sNum = 34;
    cout << "p1::sNum:" << p1.sNum << endl;
    cout << "p2::sNum:" << p2.sNum << endl;
    
    Person p3;

     
    //cout << "p3.sOther:" << p3.sOther << endl;

    system("pause");
    system("ls");
    system("pwd");
    
    system("cd ~ && ls && pwd");
    
    return 0;
}
