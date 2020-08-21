//
//  main.cpp
//  14引用reference
//
//  Created by codew on 8/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

struct Teacher{

 int mAge;

};


void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);

void testFunc(int& ref);

void AllocateAndInitByPointer(Teacher** teacher);
void AllocateAndInitByReference(Teacher*& teacher);
void test6();

void myAgeSetByReference(Teacher*& teacher);


void test7(void);
void test8(void);

void test9(void);
void test10(void);
void test11(void);
void test12(void);
void test13(void);
void test14(void);

int& TestFun01();
int& TestFunc02();
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test10();
    return 0;
}



//1\. 认识引用

void  test1(){

 int a = 10;

  //给变量a取一个别名b

 int& b = a;

 cout << "a:" << a << endl;

 cout << "b:" << b << endl;

 cout << "------------" << endl;

  //操作b就相当于操作a本身

 b = 100;

 cout << "a:" << a << endl;

 cout << "b:" << b << endl;

 cout << "------------" << endl;

  //一个变量可以有n个别名

 int& c = a;

 c = 200;

 cout << "a:" << a << endl;

 cout << "b:" << b << endl;

 cout << "c:" << c << endl;

 cout << "------------" << endl;

  //a,b,c的地址都是相同的

 cout << "a:" << &a << endl;

 cout << "b:" << &b << endl;

 cout << "c:" << &c << endl;

}

//2\. 使用引用注意事项

void  test2(){

  //1) 引用必须初始化

//  int& ref; //报错:必须初始化引用

  //2) 引用一旦初始化，不能改变引用

 int a = 10;

 int b = 20;

 int& ref = a;

 ref = b; //不能改变引用

}



void test3(void)
{
    //1\. 建立数组引用方法一

    typedef int ArrRef[10];

    int arr[10];

    ArrRef& aRef = arr;

    for (int i = 0; i < 10;i ++){

     aRef[i] = i+1;

    }

    for (int i = 0; i < 10;i++){

     cout << arr[i] << " ";

    }

    cout << endl;

    //2\. 建立数组引用方法二

    int(&f)[10] = arr;

    for (int i = 0; i < 10; i++){

     f[i] = i+10;

    }

    for (int i = 0; i < 10; i++){

     cout << arr[i] << " ";

    }

    cout << endl;
}

void test4(void)
{
    int a = 10;

     int& aRef = a; //自动转换为int* const aRef = &a;这也能说明引用为什么必须初始化

    aRef = 20; //内部发现aRef是引用，自动帮我们转换为: *aRef = 20;

    cout << "a:" << a << endl;

    cout << "aRef:" << aRef << endl;

    testFunc(a);
    
    cout << "a:" << a << endl;

    cout << "aRef:" << aRef << endl;
}


void testFunc(int& ref){

 ref = 100; // ref是引用，转换为*ref = 100

}



void test5(void)
{
    int * pointer = NULL;
    int*& p = pointer;
}



//指针间接修改teacher的年龄
void  AllocateAndInitByPointer(Teacher** teacher){

 *teacher = (Teacher*)malloc(sizeof(Teacher));

 (*teacher)->mAge = 200;

}

//引用修改teacher年龄
void  AllocateAndInitByReference(Teacher*& teacher){

 teacher->mAge = 300;

}

void myAgeSetByReference(Teacher*& teacher)
{
    teacher->mAge = 400;
}


void test6(){

    //创建Teacher
    Teacher* teacher = NULL;;

    //指针间接赋值
    AllocateAndInitByPointer(&teacher);;
    cout << "AllocateAndInitByPointer:" << teacher->mAge << endl;;

    //引用赋值,将teacher本身传到ChangeAgeByReference函数中
    AllocateAndInitByReference(teacher);
    cout << "AllocateAndInitByReference:" << teacher->mAge << endl;
    
    
    myAgeSetByReference(teacher);
    cout << "我的:" << teacher->mAge << endl;
    
    free(teacher);

}



void test7(void)
{
    int a = 100;
    
    const int& aRef = a;
    
//    aRef = 200; // 不能通过aRef赋值
    
    a = 300; // 这样是ok的
    
    cout << "a: " << a << endl;
    cout << "aRef: " << aRef << endl;
}

/**
 不能把字面量赋给引用
 */
void test8(void)
{
//    不能把字面量赋给引用
//    int& ref = 100;
    
    // 但是可以把一个字面量赋给常引用
    const int& ref = 100;
    cout << "ref: " << ref << endl;
}




/**
 常量引用主要用在函数的形参，尤其是类的拷贝/复制构造函数。

 const int& param防止函数中意外修改数据
 */
void showVal(const int& param)
{
    cout << "param:" << param << endl;
}



// 值传递
void test10(void)
{
    //不能返回局部变量的引用
    int& ret01 = TestFun01();
    
    cout << "ret01: " << ret01 << endl;

     //如果函数做左值，那么必须返回引用
    TestFunc02();

    TestFunc02() = 100;

    TestFunc02();
}

//返回局部变量引用

int& TestFun01(){

 int a = 10; //局部变量

 return a;

}

//返回静态变量引用

int& TestFunc02(){

 static int a = 20;

 cout << "static int a : " << a << endl;

 return a;

}


//void test11(void);
//void test12(void);
//void test13(void);
//void test14(void);
