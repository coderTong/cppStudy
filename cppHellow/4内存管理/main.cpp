//
//  main.cpp
//  4内存管理
//
//  Created by codew on 8/3/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

void fun1();
void fun2();
void fun3();

void fun4();
int fun5();
int *fun6();
void fun6a();
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
//    fun2();
//    fun2();
//    fun2();
    
//    fun5();
    
    fun6a();
    return 0;
}



void fun1()
{
    
    int a[10];

    memset(a, 88, sizeof(int)*6);
//    memset(a, 97, sizeof(a));
    int i = 0;
    for (i = 0; i < 10; i++)
    {
        printf("%c\n", a[i]);
    }
    
//    printf("a = %d\n", a);
}


void fun2()
{
    //静态局部变量，没有赋值，系统赋值为0，而且只会初始化一次
    static int a;
    a++;
    printf("a = %d\n", a);
}



void fun3()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int b[10];

//    memcpy(b, a, sizeof(a));
    memcpy(b, a, sizeof(int) * 4);

    int i = 0;

    for (i = 0; i < 10; i++)

    {

     printf("%d, ", b[i]);

    }

    printf("\n");

    //memcpy(&a[3], a, 5 * sizeof(int)); //err, 内存重叠
}


void fun4()
{
    int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int b[10] = { 1, 20, 30, 4, 5, 6, 7, 8, 9, 100 };

    int flag = memcmp(b, a, sizeof(a));

    printf("flag = %d\n", flag);
}


int fun5()
{
    int count;
    int *array;
    int n;
    printf("请输入要申请数组的个数:\n");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof (int));
    if (array == NULL)
    {
        printf("申请空间失败!\n");
        return -1;
    }
    //将申请到空间清0
    memset(array, 0, sizeof(int)*n);

    for (count = 0; count < n; count++) /*给数组赋值*/
        array[count] = count;

    for (count = 0; count < n; count++) /*打印数组元素*/
        printf("%2d", array[count]);

    free(array);

    return 0;
}


int *fun6()
{
    int a = 10;
    return &a;//函数调用完毕，a释放
}

void fun6a()
{
    int *p = NULL;
    p = fun6();
    /**
     1. 操作野指针指向的内存,err,
     2. 但是xcode中不报错
     2020年08月03日22:59:55
     3. 我在centos 中测试也是没有报错, 难道只有Windows平台会报错????
     */
    printf("%d \n", *p);
    *p = 100;
    
    printf("%d \n", *p);
}

