//
//  main.cpp
//  11302queue容器
//
//  Created by codew on 10/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <queue>
#include <string>
using namespace  std;

void test01()
{
    queue<int> q;
    for (int i = 0; i < 5; i++) {
        
        q.push( i + 1);
    }
    
    cout << "front :" << q.front() << endl;
    cout << "back :" << q.back() << endl;
    
    
    while ( !q.empty() ) {
        
        cout << q.front() << " ";
        q.pop();
    }
    
    cout << endl;
    cout << q.size() << endl;
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


void test02()
{
    queue< Maker *> q;
    
    q.push( new Maker("aaa", 18) );
    q.push( new Maker("bbb", 28) );
    q.push( new Maker("ccc", 38) );
    
    while ( !q.empty() ) {
        
        Maker * m = q.front();
        cout << m->name << " " << m->age << endl;
        q.pop();
        delete m;
    }
    
    cout << endl;
    cout << q.size() << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test02();
    
    return 0;
}
