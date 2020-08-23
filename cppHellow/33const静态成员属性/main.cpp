//
//  main.cpp
//  33const静态成员属性
//
//  Created by codew on 8/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person{
    
public:
    static const int m1Share = 10;
    const static int mShare = 10; // 只读区
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    cout << Person::mShare << endl;
    
    return 0;
}
