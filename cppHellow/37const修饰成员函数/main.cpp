//
//  main.cpp
//  37const修饰成员函数
//
//  Created by codew on 8/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person{
    
public:
    Person(){
        this->mAge = 0;
        this->mID = 0;
    }
    
    //在函数括号后面加上const,修饰成员变量不可修改,除了mutable变量
    void changeTest1() const{
        
        printf("%s\n", __func__);
        
        // mAge 不可修改
//        this->mAge = 200;
        this->mID = 10;
        
        this->wqnmb = 100;
        this->qnmb = 88;
    }
    
    void change2()
    {
        this->mID = 100;
        this->mAge = 200;
        showPerson();
    }
    
    void  change3()
    {
        this->mID = 100;
        this->mAge = 200;
        showPerson();
    }
    
    void showPerson(){
        
        printf("%s\n", __func__);
        cout << "ID: " << mID << " mAge:" << mAge << endl;
    }
    
    mutable int wqnmb;
    
public:
    mutable int qnmb;
    
private:
    int mAge;
    mutable int mID;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    
    Person person;
    //person.changeTest1();
    //person.showPerson();
    
    person.change2();
    
    
    return 0;
}
