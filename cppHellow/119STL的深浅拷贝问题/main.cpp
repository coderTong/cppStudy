//
//  main.cpp
//  119STL的深浅拷贝问题
//
//  Created by codew on 10/23/20.
//  Copyright © 2020 codertom. All rights reserved.
/**
 
 STL容器所提供的都是值(value)寓意，而非引用(reference)寓意，也就是说当我们给容器中插入元素的时候，容器内部实施了拷贝动作，将我们要插入的元素再另行拷贝一份放入到容器中，而不是将原数据元素直接放进容器中，也就是说我们提供的元素必须能够被拷贝

 我的话:**我们给容器元素, 容器会拷贝一份.它不是它了, 是新它**
 **我们要实现拷贝构造函数**
 */

#include <iostream>

#include <vector>
using namespace  std;

class Maker
{
public:
    Maker(int age)
    {
        cout << "age构造" << endl;
        this->age = age;
    }
    
    Maker(const Maker&m)
    {
        this->age = m.age;
        cout << "拷贝构造" << endl;
    }
    
    ~Maker()
    {
        cout << "析构函数" << endl;
    }
    
public:
    int age;
};


void test()
{
    vector<Maker> v;
    
    Maker m(10);
    
    //1.拷贝构造要能被调用
   //2.注意要浅拷贝问题
    v.push_back(m);
    
    m.age = 25;
    cout << "m age: " << m.age << endl;
    Maker m2 = v.front();
    cout << "m2 age: " << m2.age << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test();
    
    return 0;
}
