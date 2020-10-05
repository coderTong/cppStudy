//
//  main.cpp
//  60继承
//
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

#include <iostream>

using namespace std;

class BaseClass
{
    
    public:
        BaseClass()
        {
            mParam = 90;
        }
        
        void func()
        {
            cout << "BaseClass::func()" << endl;
        }
    
    public:
        int mParam;
};

class Child1 : virtual public BaseClass {};
class Child2 : virtual public BaseClass {};


class SubClass : public Child1, public Child2 {};



int main()
{
    cout << "k" << endl;
    
    SubClass subClass;
    
    subClass.func();
    
    cout << subClass.mParam << endl;
    
    cout << "SubClass: size:" << sizeof(SubClass) << endl;
    
    return 0;
}
