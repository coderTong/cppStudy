//
//  main.cpp
//  98标准异常库
//
//  Created by codew on 10/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <stdexcept>

using namespace std;

class Person{
    
public:
    Person(int age){
        
        if (age < 0 || age > 150) {
            
            throw out_of_range("年龄 应该 在 0-150 岁之间");
        }
    }
public:
    int mAge;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    try {
        Person p(151);
    } catch (out_of_range & ex) {
        
        cout << ex.what() << endl;
    }
    
    return 0;
}
