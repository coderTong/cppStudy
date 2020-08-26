//
//  main.cpp
//  41数组类
//
//  Created by codew on 8/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>
#include "MyArray.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    // 创建数组
    MyArray myArray(50);
    
    // 数组中插入元素
    for (int i = 0; i < 50; i++) {
        
        // 尾插法
        myArray.pushBack(i);
    }
    
    // 打印数组中元素
    int count = myArray.getLength();
    cout << "cout :" << count << endl;
    
    for (int i = 0; i < myArray.getLength(); i++) {
        
        cout << myArray.getData(i) << " " << endl;
    }
    
    cout << endl;
    
    
    return 0;
}
