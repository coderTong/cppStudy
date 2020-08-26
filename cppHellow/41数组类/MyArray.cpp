//
//  MyArray.cpp
//  41数组类
//
//  Created by codew on 8/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include "MyArray.hpp"



using namespace std;


MyArray::MyArray()
{
    

    cout << "come baby: " << __func__ << endl;
    
    this->mCapacity = 100;
    this->mSize = 0;
    
    // 在堆开辟空间
    this->pAddress = new int[this->mCapacity];
    
}


// 有参构造函数, 用户指定容量初始化
MyArray::MyArray(int capacity)
{
    
    cout << "come baby: " << __func__ << endl;
    
    this->mCapacity = capacity;
    this->mSize = 0;
    
    // 在堆开辟空间
    this->pAddress = new int[capacity];
}


// 根据 位置 添加元素
void MyArray::setData(int pos, int val)
{
    cout << "come baby: " << __func__ << endl;
    
    
    if ( pos < 0 || pos > mCapacity - 1 ) {
        return;
    }
    
    pAddress[pos] = val;
}

// 获得 指定 位置的 数据
int MyArray::getData(int index)
{
    cout << "come baby: " << __func__ << endl;
    
    return pAddress[index];
}

// 尾插法
void MyArray::pushBack(int val)
{
    cout << "come baby: " << __func__ << endl;
    
    
    if (mSize >= mCapacity) {
        return;
    }
    
    this->pAddress[mSize] = val;
    this->mSize++;
}

// 获得长度
int MyArray::getLength()
{
    cout << "come baby: " << __func__ << endl;
    
    return this->mSize;
}


// 析构函数
MyArray::~MyArray()
{
    cout << "come baby: " << __func__ << endl;
    
    if (this->pAddress != nullptr) {
        
        delete [] this->pAddress;
    }
}
