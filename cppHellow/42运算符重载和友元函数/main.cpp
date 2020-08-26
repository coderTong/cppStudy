//
//  main.cpp
//  42运算符重载和友元函数
//
//  Created by codew on 8/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person{
    
    friend ostream& operator<<(ostream& os, Person& person);
    
public:
    Person(int id, int age){
        
        mID = id;
        mAge = age;
    }
    
private:
    int mID;
    int mAge;
    
    
};

ostream& operator<<(ostream& os, Person& person){
    
    os << "ID: " << person.mID << " Age: " << person.mAge;
    
    return os;
}

int main(int argc, const char * argv[]) {
    
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Person person(1001, 30);
    
    cout << person << " | " << endl;
    
    return 0;
}
