//
//  main.cpp
//  11c扩展struct
//
//  Created by codew on 8/12/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);

void test6(void);
void test7(void);
void test8(void);
void test9(void);

using namespace std;

struct Student{
    string mName;
    int mAge;
    
    void setName(string name){
        mName = name;
    }
    
    void setAge(int age){
        mAge = age;
    }
    
    void showStudent(){
        cout<< "mName: " << mName <<" mAge:" <<mAge << endl;
    }
};

typedef enum COLOR{
    GREEN,
    RED,
    YELLOW
}color;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test4();
    
    return 0;
}


void test1(void)
{
    // c++可以不加struct
    Student stu;
    
    stu.setAge(20);
    stu.setName("wu");
    stu.mName = "tom";
    stu.showStudent();
}

/**
 更严格的类型转换
 */
void test2(void)
{
    color mycolor = YELLOW; // ok
//    mycolor = 10; // 错误
    mycolor = (color)0; // ok
    
    printf("mycolor:%d\n", mycolor);

    //char* p = malloc(10); // 错误
    char* p = (char*)malloc(10); // ok
}


/**
 c三目
 */
void test3(void)
{
    int a = 10;
    int b = 20;
    
    printf("ret:%d\n", a>b ? a: b);
}

/**
 cpp三目
 */
void test4(void)
{
    int a = 10;
    int b = 20;
    
    printf("ret:%d\n", a>b ? a: b);
    
    cout << "b:" << b << endl;

    // 返回的是变量的引用
    (a > b ? a : b) = 100;
    
    cout << "b:" << b << endl;

}

