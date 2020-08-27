//
//  main.cpp
//  49继承1
//
//  Created by codew on 8/27/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class MyBaseA {
    
    
public:
    int mA;
protected:
    int mB;
private:
    int mC;
    
    
};

// 1. 公有继承(public)
class ChildB : public MyBaseA {
    
    
public:
    
    void showInfo()
    {
        cout << mA << endl;
        cout << mB << endl;
        //不可访问基类private属性
//        cout << mC << endl;
    }
};


class SubB : public ChildB {
    
    
public:
    
    void showInfo()
        {
            cout << mA << endl;
            cout << mB << endl;
            //不可访问基类private属性
//            cout << mC << endl;
        }
};




// 2. 私有继承 private

class ChildC : private MyBaseA {
    
    
public:
    void showInfo()
    {
        cout << mA << endl;
        cout << mB << endl;
            
        //不可访问基类private属性
//        cout << mC << endl;
        
    }
};


class SubC : public ChildC {
    
    
public:
    void showInfo()
    {
//        不可访问基类public属性
//        cout << mA << endl;
//        不可访问基类protected属性
//        cout << mB << endl;
//        不可访问基类private属性
//        cout << mC << endl;
            
    }
};


// 3. 保护继承(protected)
class ChildD : protected MyBaseA {
    
    
public:
    void showInfo()
    {
        cout << mA << endl;
        cout << mB << endl;
            
//        不可访问基类private属性
//        cout << mC << endl;
        }
};

class SubD : ChildD {
    
    
public:
    
    void showInfo()
    {
        cout << mA << endl;
        cout << mB << endl;
                
//        不可访问基类private属性
//        cout << mC << endl;
    }

};

void test01()
{
    ChildB b;
    
    cout << b.mA << endl;
    //不可访问基类protected属性
//    cout << b.mB << endl;
    //不可访问基类private属性
//    cout << b.mC << endl;
}

void test02()
{
    ChildC c;
    
    //不可访问基类public属性
//    cout << c.mA << endl;
    //不可访问基类protected属性
//    cout << c.mB << endl;
    //不可访问基类private属性
//    cout << c.mC << endl;
}

void test03()
{
    ChildC d;
    
    //不可访问基类public属性
//    cout << d.mA << endl;
    //不可访问基类protected属性
//    cout << d.mB << endl;
    //不可访问基类private属性
//    cout << d.mC << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
