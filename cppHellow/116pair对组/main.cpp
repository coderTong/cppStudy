//
//  main.cpp
//  116pair对组
//
//  Created by codew on 10/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

#include <string>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    pair<string, int> myp("aaa", 10);
    cout << myp.first << " " << myp.second << endl;
    
    pair<int, string> myp2(1, "nibaba");
    cout << myp2.first << " " << myp2.second << endl;
    
    // key-->value
    
    
    
    return 0;
}
