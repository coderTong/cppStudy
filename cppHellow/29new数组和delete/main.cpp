//
//  main.cpp
//  29new数组和delete
//
//  Created by codew on 8/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);


class Person {
    
    
public:
    Person(){
        
        cout  << "无参构造函数" << endl;
        pName = (char*)malloc(strlen("undefined") + 1);
        strcpy(pName, "undefined");
        mAge = 0;
    }
    
    Person(char* name, int age){
        
        cout  << "有参构造函数" << endl;
        pName = (char*)malloc( sizeof(name) );
        strcpy(pName, name);
        mAge = age;
    }
    
    ~Person(){
        
        if (pName != NULL) {
            delete pName;
        }
    }
    
public:
    char* pName;
    int mAge;
};

//堆上
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test2();
    
    return 0;
}


void test1(void)
{
    // 创建字符数组
    char * pStr = new char[100];
    
    // 创建整型数组
    int * pArr1 = new int[100];
    
    // 创建整型数组 并 初始化
    int * pArr2 = new int[5]{1,2,3,4,5};

    // 释放数组内存
    delete[] pStr;
    delete[] pArr1;
    delete[] pArr2;
}


void test2(void)
{
    
    // 栈聚合初始化
    Person person[] = {
        Person("john", 20),
        Person("tom", 23)
    };
    
    cout << person[1].pName << endl;
    
    // 创建堆上对象数组 必须提供构造函数
    
    Person * workers = new Person[20]; // 自动调用20次无参 构造函数
    
    
}
