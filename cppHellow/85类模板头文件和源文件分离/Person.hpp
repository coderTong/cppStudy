//
//  Person.hpp
//  85类模板头文件和源文件分离
//
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp

#include <stdio.h>

#pragma once

using namespace std;


template <class T1, class T2>
class Person {
    
public:
    
    Person(T1 name, T2 age);
    void showPerson();
    
public:
    T1 name;
    T2 age;
};

template <class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
    this->name = name;
    this->age = age;
}

template <class T1, class T2>
void Person<T1, T2>::showPerson()
{
    cout << "name: " << this->name << "  age: " << this->age << endl;
}

#endif /* Person_hpp */
