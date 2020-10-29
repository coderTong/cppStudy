//
//  main.cpp
//  127算术生成算法
//
//  Created by codew on 10/25/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
#include <numeric> // 算术生成算法的头文件

using namespace std;


//accumulate算法 计算容器元素累计总和
void test01()
{
    vector<int> v;
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    //第三个参数是在总和上再加上0
    
    int ret = accumulate(v.begin(), v.end(), 10);
    cout << ret << endl;
    
}

class Maker
{
public:
    Maker(int age)
    {
        this->age = age;
    }
    
public:
    int age;
};


struct MyPuls
{
    int operator()(int val, Maker &m)
    {
        return val + m.age;
    }
};


void test02()
{
    vector<Maker> v;
    
    v.push_back( Maker(10) );
    v.push_back( Maker(20) );
    v.push_back( Maker(30) );
    
    int ret = accumulate(v.begin(), v.end(), 10, MyPuls() );
    cout << ret << endl;
    
}

// fill 算法 向容器 中 添加 元素

void test03()
{
    
    vector<int> v;
    
    // 要 开辟 空间
//    v.resize(10);
    
    for (int i = 0; i < 3; i++) {
        
        v.push_back(i);
    }
    
    fill(v.begin(), v.end(), 100);
    
    for_each(v.begin(), v.end(), [](int val){
        
        cout << val << " ";
    });
    
    cout << endl;
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test03();
    
    return 0;
}
