//
//  main.cpp
//  28new对象
//
//  Created by codew on 8/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
    
public:
    Person(){
        cout << "无参数构造" <<endl;
        
        pName = (char*)malloc(strlen("undefined") + 1);
        strcpy(pName, "undefined");
        mAge = 0;
    }
    
    Person(char *name, int age){
        cout << "参数构造" <<endl;
        
        pName = (char*)malloc(strlen(name) + 1);

        strcpy(pName, name);

        mAge = age;
    }
    
    void showPerson(){
        
        cout << "name: " << pName << " mAge" << endl;
    }
    
    ~Person(){
        cout << "析构函数" <<endl;
        
        if (pName != NULL) {
            
            delete pName;
            pName = NULL;
        }
    }
    
public:
    int mAge;
    char *pName;
    
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
//    Person *person = new Person;
//    delete person;
    
    Person* person1 = new Person;

    Person* person2 = new Person("John",33);

    person1->showPerson();

    person2->showPerson();

    delete person1;

    delete person2;
    
    return 0;
}
