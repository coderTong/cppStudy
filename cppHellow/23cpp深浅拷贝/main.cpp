//
//  main.cpp
//  23cpp深浅拷贝
//
//  Created by codew on 8/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
  
public:
    Person(char *name, int age){
        
        cout << "有参数....." << endl;
        pName = (char *)malloc( sizeof(name) + 1 );
        strcpy(pName, name);
        mAge = age;
    }
    
    // 拷贝构造函数
    Person(const Person& person){
        
        cout << "拷贝构造....." << endl;
        pName = (char *)malloc( strlen(person.pName) + 1);
        strcpy(pName, person.pName);
        mAge = person.mAge;
    }
    
    ~Person(){
        
        if (pName != NULL) {
            
            free(pName);
        }
    }
    
private:
    int mAge;
    char *pName;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Person p1("Edward",30);

     //用对象p1初始化对象p2,调用c++提供的默认拷贝构造函数

    Person p2 = p1;
    
    
    return 0;
}
