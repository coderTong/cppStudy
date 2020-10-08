//
//  main.cpp
//  84类模板类外实现
//  2020年10月05日22:11:00
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

template<class T1, class T2>
class Person{
    
public:
    Person(T1 name, T2 age);
    void showPerson();
    
public:
    T1 name;
    T2 age;
};


// 类外 实现
template<class T1, class T2>
Person<T1, T2> :: Person(T1 name , T2 age)
{
    this->name = name;
    this->age = age;
}

// 类外 实现
template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
    
    cout << " name : " << this->name << " age: " << this->age << endl;
}

void test()
{
    Person<string, int> p("狂铁", 20);
    p.showPerson();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    test();
    return 0;
}
