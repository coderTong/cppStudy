//
//  main.cpp
//  112stack容器
//
//  Created by codew on 10/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <stack>
#include <string>

using namespace std;


// 栈容器, 先进先出
// 存储基础数据类型
void test01()
{
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    
    // 输出栈中的元素
    while ( !s.empty() ) {
        
        // 输出栈顶元素
        cout << s.top() << " ";
        // 弹出栈顶元素
        s.pop();
    }
    
    cout << "size: " << s.size() << endl;
}

class Maker
{
public:
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
public:
    string name;
    int age;
};


// 存储对象
void test02()
{
    stack<Maker> s;
    s.push( Maker("aaa", 18) );
    s.push( Maker("bbb", 19) );
    s.push( Maker("ccc", 20) );
    
    
    while ( !s.empty() ) {
        
        cout << "name :" << s.top().name << "age: " << s.top().age << endl;
        s.pop();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test02();
    
    return 0;
}
