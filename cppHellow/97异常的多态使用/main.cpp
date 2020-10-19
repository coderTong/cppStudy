//
//  main.cpp
//  97异常的多态使用
//
//  Created by codew on 10/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class BaseException
{
public:
    virtual void printError(){
        
    }
};

class NullPointerException : public BaseException
{
public:
    virtual void printError(){
        
        cout << "空指针 异常!" << endl;
    }
};

class OutOfRangeException : public BaseException
{
public:
    virtual void printError(){
        
        cout << "越界 异常!" << endl;
    }
};

void doWork(){
    
    throw OutOfRangeException();
}

void test()
{
    try {
        doWork();
    } catch (BaseException &ex) {
        
        ex.printError();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test();
    return 0;
}
