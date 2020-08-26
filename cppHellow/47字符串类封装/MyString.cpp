//
//  MyString.cpp
//  47字符串类封装
//
//  Created by codew on 8/26/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include "MyString.hpp"


// 构造和析构 ========================================================================
MyString::MyString()
{
    this->mLength = 0;
    this->pAddress = new  char[1];
    this->pAddress[0] = '\0';
    
}
MyString::MyString(const char* p)
{
    this->mLength = strlen(p);
    this->pAddress = new char[this->mLength + 1];
    strcpy(this->pAddress, p);
}
MyString::MyString(const MyString& obj)
{
    this->mLength = obj.mLength;
    this->pAddress = new char[this->mLength + 1];
    strcpy(this->pAddress, obj.pAddress);
}
MyString::~MyString()
{
    if ( this->pAddress != NULL) {
        
        delete [] this->pAddress;
    }
}

// 普通成员函数 ========================================================================
const char* MyString::c_str() const
{
    return this->pAddress;
}
int MyString::length() // 获取字符串长度
{
    return this->mLength;
}

// 运算符重载 << 重载, 友元函数 ========================================================================
ostream& operator<<(ostream& out, MyString& obj)
{
    out << obj.pAddress;
    return out;
}
void operator>>(const char* str, MyString& obj)
{
    if ( obj.pAddress != NULL) {
        
        delete [] obj.pAddress;
    }
    
    obj.pAddress = new char[ strlen(str) + 1];
    
    for (int i = 0; i < strlen(str) + 1; i++) {
        
        obj.pAddress[i] = '\0';
    }
    
    strcpy(obj.pAddress, str);
}

// =, [] 重载 ========================================================================
MyString& MyString::operator=(const MyString& obj)
{
    if ( this->pAddress != NULL) {
        
        delete [] this->pAddress;
        this->pAddress = NULL;
    }
    
    this->mLength = obj.mLength;
    this->pAddress = new char[ this->mLength + 1];
    strcpy( this->pAddress,  obj.pAddress);
    
    return *this;
    
    
}
MyString& MyString::operator=(const char* p)
{
    if ( this->pAddress != NULL) {
        
        delete [] this->pAddress;
        this->pAddress = NULL;
    }
    
    this->mLength = strlen(p);
    this->pAddress = new char[this->mLength + 1];
    
    strcpy(this->pAddress, p);
    return *this;
    
}
char& MyString::operator[](int index)
{
    return this->pAddress[index];
}

// 重载+=, + ========================================================================
MyString& MyString::operator+=(MyString& str)
{
    // 判断追加的 字符串 是否 为空
    if ( str.mLength == 0) {
        
        return *this;
    }
    
    // 计算 两个 字符串 总长
    this->mLength = this->mLength + str.mLength;
    
    // 申请两个字符串长度的空间
    char* pTemp = new char[this->mLength + 1];
    
    // 初始化数组
    for (int i = 0; i < this->mLength + 1; i++) {
        
        pTemp[i] = '\0';
    }
    
    // 拷贝两个 字符串 到新空间中
    
    char* p = pTemp;
    strcat(p, this->pAddress);
    strcat(p, str.pAddress);
    
    // 释放 旧空间
    if ( this->pAddress != NULL) {
        
        delete [] this->pAddress;
        this->pAddress = NULL;

    }

    // 更新pAddress指针
    this->pAddress = pTemp;
    return *this;
    
}
MyString& MyString::operator+=(const char*s)
{
    // 判断 追加的 字符串 是否 为空
    
    if ( s == NULL || strlen(s) == 0 ) {
        
        return *this;
    }
    
    // 计算 两个字符串 总长
    this->mLength = this->mLength + strlen(s);
    
    // 申请两个 字符串 长度的 空间
    char * pTemp = new char[this->mLength + 1];
    
    // 初始化 数组
    for (int i = 0; i < this->mLength + 1; i++) {
        
        pTemp[0] = '\0';
    }
    
    // 判断 两个 字符串 到 新空间 中
    strcat(pTemp, this->pAddress);
    strcat(pTemp, s);
    
    // 释放旧空间
    if ( this->pAddress != NULL ) {
        
        delete [] this->pAddress;
        this->pAddress = NULL;
    }
    
    // 更新指针
    this->pAddress = pTemp;
    
    return *this;
}
MyString MyString::operator+(MyString& str)
{
    if (str.mLength == 0) {
        
        return *this;
    }
    
    MyString tempString;
    tempString.mLength = this->mLength + str.mLength;
    tempString.pAddress = new char[tempString.mLength + 1];
    
    // 初始化 数组
    
    for (int i = 0; i < tempString.mLength + 1; i++) {
        
        tempString.pAddress[i] = '\0';
    }
    
    strcat(tempString.pAddress, this->pAddress);
    strcat(tempString.pAddress, str.pAddress);
    
    return tempString;
}
MyString MyString::operator+(const char* str)
{
    if ( str == NULL || strlen(str) == 0) {
        
        return *this;
    }
    
    MyString tempString;
    tempString.mLength = this->mLength + strlen(str);
    tempString.pAddress = new char[tempString.mLength + 1];
    
    for (int i = 0; i < tempString.mLength + 1; i++) {
        
        tempString.pAddress[i] = '\0';
    }
    
    strcat(tempString.pAddress, this->pAddress);
    strcat(tempString.pAddress, str);
    
    return tempString;
}

// 重载 ==, != ccc========================================================================
bool MyString::operator==(const char* p)
{
    if ( p == NULL) {
        
        return false;
    }
    
    
    if ( strcmp(this->pAddress, p) == 0 ) {
        
        return true;
    }
    
    return false;
}
bool MyString::operator!=(const char* p)
{
    if (p == NULL) {
        
        return false;
    }
    
    if (strcmp( this->pAddress, p) != 0) {
        
        return true;
    }
    
    return false;
}
bool MyString::operator==(MyString& obj)
{
    if ( strcmp(this->pAddress, obj.pAddress) == 0) {
        
        return true;
    }
    
    return false;
}
bool MyString::operator!=(MyString& obj)
{
    if ( strcmp(this->pAddress, obj.pAddress) != 0 ) {
        
        return true;
    }
    
    return false;
}
