//
//  main.cpp
//  cppHellow02
//
//  Created by codew on 7/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

void test01();

using namespace std;

namespace NameS01 {

int valueA = 500;
int valueB = 600;

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test01();
    
    
    return 0;
}



void test01()
{
    cout << "你瞅啥!!!" << endl;
    
    cout << "你瞅啥!!!--没有using之前--valueA:" << NameS01::valueA << endl;
    cout << "你瞅啥!!!--没有using之前--valueB:" << NameS01::valueB << endl;
    
//    using 声明是让命名空间中某个标识符可以直接使用
//    using NameS01::valueA;
//    using NameS01::valueB;
    
//    cout << "你瞅啥!!!--using之后--valueA:" << valueA << endl;
//    cout << "你瞅啥!!!--using之后--valueB:" << valueB << endl;
    
    
    using namespace NameS01;
    
    // 就近原则
    int valueA = 9000;
    
    cout << "你瞅啥!!!--using namespace NameS01--valueA:" << valueA << endl;
    cout << "你瞅啥!!!--using namespace NameS01--valueB:" << valueB << endl;
    
    
}
