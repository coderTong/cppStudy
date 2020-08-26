//
//  main.cpp
//  46指针运算符重载
//
//  Created by codew on 8/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person{
    
public:
    Person(int param){
        
        this->mParam = param;
    }
    
    void showInfo()
    {
        cout << "Param: " << mParam << endl;
    }
    
    ~Person()
    {
        
        cout << "Person的析构函数: " << mParam << endl;
    }
  
private:
    int mParam;
    
};


class SmartPointer{
  
public:
    SmartPointer(Person* person){
        
        this->pPerson = person;
    }
    
    // 重载指针的 -> , * 操作符
    Person* operator->(){
        
        return pPerson;
    }
    
    Person& operator*(){
        
        return *pPerson;
    }
    
    ~SmartPointer(){
        
        cout << "SmartPointer的析构函数" << endl;
        
        if ( pPerson != NULL ) {
            
            delete pPerson;
        }
    }
    
public:
    Person* pPerson;
};


void test01()
{
    // 堆的对象需要手动释放
    Person* person = new Person(101);
    
    
    SmartPointer pointer( new Person(100) );
    pointer->showInfo();
    

    delete person;
    
    // 栈的不需要delete手动释放, 手动去释放的话反而被报错
//    delete pointer;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    test01();
    return 0;
}
