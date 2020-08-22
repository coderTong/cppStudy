//
//  main.cpp
//  21cpp构造函数的分类及调用
//
//  Created by codew on 8/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;
class Person {
    
    
    
public:
    Person (){
        
        cout << "无参数构造函数" << endl;
        mAge = 0;
    }
    
    // 有参构造函数
    Person (int age){
        
        cout << "有参数构造函数" << endl;
        mAge = age;
    }
    
    // 拷贝构造函数(复制构造函数) 使用另一个对象初始化本对象
    Person (const Person& person){
        
        cout << "拷贝构造函数" << endl;
        mAge = person.mAge;
    }
    
    void showAge()
    {
        cout << "Age:" << mAge << endl;
    }
    
    
private:
    int mAge;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    // 无参数
    Person p;
    p.showAge();
    
    // 有参数
    Person p2(100);
    p2.showAge();
    
    Person p3(p2);
    p3.showAge();
    
    
    Person p4 = Person(28);
    p4.showAge();
    
    Person p5 = 29; // Person p5 = Person(29);
    p5.showAge();
    
    
    
    Person p6 = p5;
    p6.showAge();
    
    
    
    Person p7;
    // 不能调用拷贝构造函数去初始化匿名对象,
//    Person(p7); // 错误
    
    return 0;
}
