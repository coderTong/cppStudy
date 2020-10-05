//
//  main.cpp
//  54继承
//
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
//  析构函数


#include <iostream>

using namespace std;


class BaseClass
{
    public:
        int mA;
        int mB;
        
    BaseClass()
    {
        cout << __func__ << endl;
    }
    
    ~BaseClass()
    {
        cout << __func__ << endl;
    }
        
};

class SubA : BaseClass
{
    public:
        int mC;
    
    SubA()
    {
        cout << __func__ << endl;
    }
    
    ~SubA()
    {
        cout << __func__ << endl;
    }
};


class SubB : SubA
{
    public:
        int mD;
        
    SubB()
    {
        cout << __func__ << endl;
    }
    
    ~SubB()
    {
        cout << __func__ << endl;
    }
};

int main()
{
    cout << "hello dealloc" << endl;
    
    SubB b;
    return 0;
}

