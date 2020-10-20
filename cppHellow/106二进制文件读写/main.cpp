//
//  main.cpp
//  106二进制文件读写
//
//  Created by codew on 10/20/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>

//#include <stdio.h>
//#include <stdlib.h>
using namespace std;

class Person
{
public:
    Person(){}
    Person(string name, int age)
    {
        
        this->name = name;
        this->age = age;
    }
    
public:
    // string 类中有一个 成员指针 char *, 该指针 指向 存储字符串的空间
    // 当我们把string 类的数据 存储到文件中,  再读出来时, 不能保证指针有效
    // string开辟的空间 如果大于 16个 字节就在 堆区, 小于就在栈区
    string name;
    
    int age;
};


// 写文件
void test01()
{
    Person p1("二傻子", 18);
    Person p2("呆逼", 22);
    
    ofstream ofs;
    /**
     ios:out 以输出方式打开文件( 这是默认方式), 如果已有此名的文件, 则将其原有内容全部清除
     ios::trunc 打开一个文件, 如果文件已存在, 则删除其中全部数据, 如果文件不存在, 则建立新文件. 如已指定了ios:out方式, 而未指定 ios::app , ios::ate, ios::in 则同时默认此方式
     ios::binary 以二进制方式, 打开一个文件, 如果不指定此方式, 则默认为 ASCII 方式
     */
    ofs.open("p.txt", ios::out | ios::trunc | ios::binary);
    if ( !ofs.is_open() ) {
        
        cout << "打开失败" << endl;
    }
    
    // 写
    ofs.write( (const char *)&p1, sizeof(Person));
    ofs.write( (const char *)&p2, sizeof(Person));
    
    ofs.close();
}

// 读文件
void test02()
{
    ifstream ifs;
    ifs.open("p.txt", ios::in | ios::binary);
    if ( !ifs.is_open() ) {
        
        cout << "打开失败" << endl;
    }
    
    Person p1;
    Person p2;
    
    ifs.read( (char*)&p1, sizeof(Person));
    ifs.read( (char*)&p1, sizeof(Person));
    
    cout << "name: " << p1.name << " age : " << p1.age <<endl;
    cout << "name: " << p2.name << " age : " << p2.age <<endl;
    
    ifs.close();
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test02();
    return 0;
}
