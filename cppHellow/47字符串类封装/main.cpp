//
//  main.cpp
//  47字符串类封装
//
//  Created by codew on 8/26/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include "MyString.hpp"

//1\. 测试+=

void  test01(){

 MyString str1("bbb");

 MyString str2("aaa");

 str1 += str2;

 cout << "str1:" << str1 << endl;

 str1 += "hello world!";

 cout << "str1:" << str1 << endl;

}

//2\. 测试+

void  test02(){

 MyString str1("bbb");

 MyString str2("aaa");

 MyString str3 = str1 + str2; //有问题

 cout << "str1:" << str1 << endl;

 cout << "str2:" << str2 << endl;

 cout << "str3:" << str3 << endl;

 cout << "-----------------" << endl;

 MyString str4 = str1 + "hello world!";

 cout << "str1:" << str1 << endl;

 cout << "str4:" << str4 << endl;

}

//3\. 测试=、[]

void  test03(){

 MyString str1("bbb");

 MyString str2("aaa");

 cout << "str1:" << str1 << endl;

 cout << "str2:" << str2 << endl;

 cout << "---------------" << endl;

 str1 = str2;

 cout << "str1:" << str1 << endl;

 cout << "str2:" << str2 << endl;

 cout << "---------------" << endl;

 cout << "[]:";

 for (int i = 0; i < str1.length(); i++){

 cout << str1[i];

 }

 cout << endl;

}

//4\. 测试==、!=

void  test04(){

 MyString str1("bbb");

 MyString str2("aaa");

 if (str1 != str2){

 cout << "不相等!" << endl;

 }

 if (str1 != "ccc"){

 cout << "不相等!" << endl;

 }

 str2 = str1;

 if (str1 == str2){

 cout << "相等!" << endl;

 }

 if (str1 == "bbb"){

 cout << "相等!" << endl;

 }

}

//5\. 拷贝构造、=

void  test05(){

 MyString str1("bbb");

 MyString str2 = str1;

 MyString str3(str1);

 cout << "str1:" << str1 << endl;

 cout << "str2:" << str2 << endl;

 cout << "str3:" << str3 << endl;

}

//6\. 右移运算符

void  test06(){

 MyString str;

  "hello world" >> str;

 cout << "str:" << str << endl;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test01();
    
    return 0;
}
