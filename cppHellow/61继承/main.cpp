//
//  main.cpp
//  61继承
//
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class BaseClass
{
    
    public:
        BaseClass(int age)
        {
            this->age = age;
        }
        
        void showInfo()
        {
            cout << "age: " << age << endl;
        }
    
    public:
        int age;
};

class Sub1 : virtual public BaseClass
{
    public:
        //不调用BigBase构造
        Sub1():BaseClass(99)
        {
        }
};

class Sub2 : virtual public BaseClass
{
    public:
        //不调用BigBase构造
        Sub2():BaseClass(66)
        {
        }
};


class Derived : public Sub1, public Sub2
{
    public:
        Derived() : BaseClass(88)
        {
        }
};

int main()
{
    
    cout << "hello cpp" << endl;
    
    Derived obj;
    
    obj.showInfo();
    
    return 0;
}

