//
//  main.cpp
//  pointer
//
//  Created by codew on 8/2/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;
void test4();
void test5();

void showArr(int * pArr, int len);
void test6();
void test7();
void changeArr(int * pArr);

void test9();
void test10();
void test11();

int * test12();

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int * pk = test12();
    
    printf("%x \n", pk);
    *pk = 8090;
    printf("%d \n", *pk);
    return 0;
}
/**
 返回局部变量地址, 地址是可以打印, 但是值马上就没了
 */
int * test12()
{
    int k = 90;
    
    int * pk = &k;
    
    printf("-%x \n", pk);
    printf("-%d \n", *pk);
    return pk;
}

/**
 
 计算数组个数
 */
void test11()
{
    int a[6] = {0, 1, 2, 3, 4, 6};
    
    int v = sizeof(a) / sizeof(a[0]);
    
    printf("%d \n", sizeof(a));
    printf("%d \n", sizeof(a[0]));
    printf("%d \n", v);
    
    int a1[5] = {0, 1, 2, 3, 4};
    
    int v1 = sizeof(a1) / sizeof(a1[0]);
    
    printf("%d \n", sizeof(a1));
    printf("%d \n", sizeof(a1[0]));
    printf("%d \n", v1);
    
    int * p = a;
    
    printf("%d \n", sizeof(p));
}
/**
 
 看看指针占几个字节
 */
void test10()
{
    char valueS = 'A';
    int valueI = 80;
    double valueD = 90.3f;
    
    char * p1 = &valueS;
    int * p2 = &valueI;
    double * p3 = &valueD;
    
    
    printf("char * %d \n", sizeof(p1));
    printf("int * %d \n", sizeof(p2));
    printf("double * %d \n", sizeof(p3));
}
/**
 
 指针相减
 */
void test9()
{
    int a[5] = {0, 1, 2, 3, 4};
    
    int *p = a;
    int *q = &a[4];
    
    int value = q - p;
    // 4
    printf("两个元素相隔%d个单元", value);
    
}
void test8()
{
    int a[5] = {0, 1, 2, 3, 4};
    
    
    changeArr(a);
    
    for (int i = 0; i < 5; i++){
     
        printf("%d \n", a[i]);
    }
}

void test7()
{
    int a[5] = {0, 1, 2, 3, 4};
    
    
    showArr(a, 5);
    
    
}

void changeArr(int * pArr)
{
    pArr[3] = 88;
}

void showArr(int * pArr, int len)
{
    for (int i = 0; i < len; i++) {
        
//        printf("%d", *(pArr+i) );
        
        // 也可以写成
        printf("%d", pArr[i] );
    }
}


/**
 一维数组名就是第一个元素的地址
 一维数组是常量不可改变
 */
void test6()
{
    int a[5] = {0, 1, 2, 3, 4};
    int b[5] = {0, 1, 2, 3, 4};
    printf("%x \n", a);
    
    printf("%#x  \n", &a[0]);
    
    // 一维数组是常量不可改变
//    a = &b[2];
    
    for (int i = 0; i < 5; i++){
     
        printf("%d \n", a[i]);
    }
}

// 互换两个值 指针方法
void test5()
{
    int a = 9;
    int b = 3;
    
    int * p;
    int * q;
    
    int  t;
    
    p = &a;
    q = &b;
    
//    cout << "*p = " << *p << " *q = " << *q << endl;
    
    t = *p;
    
    *p = *q;
    *q = t;
    
    
    
    
//    b = *q;
//    a = *p;
    
    
//    cout << "*p = " << *p << " *q = " << *q << endl;
    cout << "a = " << a << " b = " << b << endl;
}

// 互换两个值 普通方法
void test4()
{
    int a = 9;
    int b = 3;
    
    int t;
    
    t = a;
    a = b;
    b = t;
    
    cout << "a = " << a << " b = " << b << endl;
}


void test3()
{
    int * p;
    
    cout << "*p = " << p << endl;
    
}

/**
 错误查询
 野指针
 */
void test2()
{
    int * p;
    
    int i = 3;
    
    *p = i;
    
    cout << "*p = " << *p << endl;
}

void test()
{
    
    int * p;
    
    int i = 3;
    int j;
    
    p = &i;
    
     
    cout << "*p = " << *p << endl;
}
