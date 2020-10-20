//
//  main.cpp
//  104对二进制文件的读写操作
//
//  Created by codew on 10/20/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <fstream>

using namespace std;

class Person
{
public:
    Person()
    {
        
    }
    Person(char *name, int age)
    {
        strcpy(this->mName, name);
        this->mAge = age;
    }
    
public:
    char mName[64];
    int mAge;
};



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    char* fileName = "person.txt";
    
    //二进制模式读写文件
    //创建文件对象输出流
    
    ofstream osm(fileName, ios::out | ios::binary);
    
    Person p1("tom", 34);
    Person p2("json", 23);
    
    // Person 对象 写入 文件
    osm.write((const char*)&p1, sizeof(Person));
    osm.write( (const char*)&p2, sizeof(Person));
    
    // 关闭文件输出流
    osm.close();
    
    
    // 从文件中读 取 对象 数组
    ifstream ism(fileName, ios::in | ios::binary);
    
    if ( !ism ) {
        cout << "打开文件失败???? " << endl;
    }
    
    Person p3;
    Person p4;
    
    ism.read( (char *)&p3, sizeof(Person));
    ism.read( (char *)&p4, sizeof(Person));
    
    cout << "Name: " << p3.mName << " Age: " << p3.mAge << endl;
    cout << "Name: " << p4.mName << " Age: " << p4.mAge << endl;
    
    ism.close();
    
    system("pwd");
    return 0;
}
