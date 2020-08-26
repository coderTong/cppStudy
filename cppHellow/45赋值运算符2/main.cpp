//
//  main.cpp
//  45赋值运算符2
//
//  Created by codew on 8/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
    
    friend ostream& operator<<(ostream& os, const Person& person)
    {
        os << " ID: " << person.mID << " mAge: " << person.mAge << endl;
        return os;
    }
    
public:
    Person(int id, int age){
        
        cout << "Person 构造函数" << endl;
        this->mID = id;
        this->mAge = age;
    }
    
    // 第一个 重载赋值运算符
    Person operator=(int x){
        
        cout << "第一个 重载赋值运算符" << endl;
        this->mID = x;
        this->mAge = x;
        
        cout << "重载一函数内:" <<*this << endl;
        
        return *this;
    }
    
    // 第二个 重载 赋值运算符
    Person operator=(const Person& person){
        
        cout << "第二个 重载 赋值运算符" << endl;
        this->mID = person.mID;
        this->mAge = person.mAge;
        
        return *this;
    }
    
private:
    int mID;
    int mAge;
};


void test()
{
    Person person1(1001, 16);
    Person person2(1002, 17);
    
    cout << "person1: " << person1;
    cout << "person2: " << person2;
    
    //由于person2 = person1返回的是临时对象，所以赋值为10并没有改变person2对象
    (person2 = person1) = 10;
    
    // 这样的话就是10了
//    person2 = person1 = 10;
    
    cout << "person2: " << person2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test();
    return 0;
}
