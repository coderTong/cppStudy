//
//  main.cpp
//  83类模板类内实现
//
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
//

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
    
    // error 类模板 不能 进行 类型 自动推导
//    Person p0("亚瑟", 78);
    
    Person<string, int>p1("李白", 18);
    p1.showPerson();
    
    return 0;
}
