//
//  main.cpp
//  119STL的深浅拷贝问题
//
//  Created by codew on 10/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

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
