//
//  MyArray.hpp
//  41数组类
//
//  Created by codew on 8/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#ifndef MyArray_hpp
#define MyArray_hpp

#include <iostream>
#include <stdio.h>

class MyArray {
    
    
public:
    // 无参构造函数, 用户没有指定容量, 则初始化为100
    MyArray();
    // 有参构造函数, 用户指定容量初始化
    // C++提供了关键字explicit，禁止通过构造函数进行的隐式转换。声明为explicit的构造函数不能在隐式转换中使用。
    explicit MyArray(int capacity);
    
    // 用户操作接口 =================================
    // 根据 位置 添加元素
    void setData(int pos, int val);
    
    // 获得 指定 位置的 数据
    int getData(int index);
    
    // 尾插法
    void pushBack(int val);

    // 获得长度
    int getLength();
    
    // 析构函数
    ~MyArray();
    
private:
    // 数组一共可容纳多少个元素
    int mCapacity;
    // 当前有多少个元素
    int mSize;
    // 指向存储数据的空间
    int *pAddress;
};

#endif /* MyArray_hpp */
