//
//  main.cpp
//  79类模板
//
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
/**
 2020年10月05日21:37:24
 隔了一段时间再学一下
 
 类模板基本概念
 
 */

#include <iostream>

using namespace std;


template <class NameType, class AgeType>

class Person
{
public:
    Person(NameType name, AgeType age)
    {
        this->name = name;
        this->age = age;
    }
    void showPerson()
    {
        cout << "name: " << this->name << " age: " << this->age << endl;
    }
    
public:
    NameType name;
    AgeType age;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Person<string, int>p1("亚瑟", 20);
    p1.showPerson();
    
    return 0;
}
