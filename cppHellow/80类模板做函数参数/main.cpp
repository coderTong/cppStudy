//
//  main.cpp
//  80类模板做函数参数
//
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
/*

 2020年10月05日21:55:46
 类模板做函数参数
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

// 类模板函数
void doBussiness(Person<string, int> &p)
{
    p.age += 20;
    p.name += "_vip";
    p.showPerson();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Person<string, int>p("tom", 30);
    doBussiness(p);
    
    
    system("pause");
    
    return 0;
}
