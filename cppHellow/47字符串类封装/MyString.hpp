//
//  MyString.hpp
//  47字符串类封装
//
//  Created by codew on 8/26/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#ifndef MyString_hpp
#define MyString_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
class MyString {
    
    
public:
    // 构造和析构
    MyString();
    MyString(const char* p);
    MyString(const MyString& obj);
    ~MyString();
    
    // 普通成员函数
    const char* c_str() const;
    int length(); // 获取字符串长度
    
    // 运算符重载 << 重载, 友元函数
    friend ostream& operator<<(ostream& out, MyString& obj);
    friend void operator>>(const char* str, MyString& obj);
    
    // =, [] 重载
    MyString& operator=(const MyString& obj);
    MyString& operator=(const char* p);
    char& operator[](int index);
    
    // 重载+=, +
    MyString& operator+=(MyString& str);
    MyString& operator+=(const char*s);
    MyString operator+(MyString& str);
    MyString operator+(const char* str);
    
    // 重载 ==, !=
    bool operator==(const char* p);
    bool operator!=(const char* p);
    bool operator==(MyString& obj);
    bool operator!=(MyString& obj);
    
private:
    char *pAddress;
    int mLength;
};


#endif /* MyString_hpp */
