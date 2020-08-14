//
//  main.c
//  5复合类型
//
//  Created by codew on 8/4/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>

#include <stdlib.h>

struct stu
{
    int num;
    char name[20];
    char sex;
    float score;
    int age;
    
}Bob;


struct person
{
    char name[20];
    char sex;
};

struct coder
{
    int id;
    struct person info;
};


struct iOSer
{
    char *name;
    int age;
};

typedef struct coder IOSCoder;

typedef struct Student
{
    char name[50];
    int age;
}Student;

enum MyWeekDay
{
  sun,
  mon
};


void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);

void test6(void);
void test7(void);
void test8(void);
void test9(void);
void test9a(struct coder iOSer);

void test10(void);
void test10a(struct coder * iOSer);


void test11(void);
void test11a(struct coder * iOSer, int count);


void test12(void);
void test12a(struct coder * const iOSer);
void test121(struct coder * iOSerP);
void test12b(const struct coder * iOSerP);
void test12c(const struct coder * const iOSerP);
void test13(void);
void test14(void);
void test15(void);
void test16(void);



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
//    test14();
    
    int a = -4312205;
    
    float value1 = 6.123456;
    
//    printf("%018d\n", a);
//    printf("%+d\n", a);
//    printf("%+d\r", a);
//    printf("%+d\t", a);
//    printf("%+d\t", a);
//    printf("%+d\t", a);
//
//    printf("%+d\a", a);
//    printf("%+d\a", a);
//    printf("%+d\a", a);
//    printf("%12.4f\n", value1);;
    int m = 4, n = 5, i = 2, f = 3;
    
    printf("%*d\n", m, i);
    printf("% *.* d\n", m, n, f);
    
    return 0;
}


/**
 
 结构体普通变量用.
 */
void test1()
{
    
    Bob.age = 90;
    strcpy(Bob.name, "abc");
    
    printf("age %d \n", Bob.age);
    printf("name %s \n", Bob.name);
    
    
    memset(Bob.name,99,sizeof(Bob.name));
    printf("name %s \n", Bob.name);
    
    // 居然没有越界错误.....
    char name2[30] = "abcdefghij abcdefghij abcdefghij";
    memcpy(Bob.name, name2, sizeof(name2));
    printf("name %s \n", Bob.name);
    
}
/**
 结构体指针变量用->
 */
void test2()
{
    struct stu yaojun;
    
    (&yaojun)->age = 27;
    strcpy((&yaojun)->name, "yaojun");
    
    printf("age %d \n", (&yaojun)->age);
    printf("name %s \n", (&yaojun)->name);
    
    
    char name2[20] = "yaojun666";
    memcpy((&yaojun)->name, name2, sizeof(name2));
    printf("name %s \n", (&yaojun)->name);
    
    
}
/**
 结构体数组
 
 */
void test3()
{
    //定义一个含有5个元素的结构体数组并将其初始化
//    struct stu boy[5] = {
//        { 101, "Li ping", 'M', 45, 25 },
//        { 102, "Zhang ping", 'M', 62.5, 25 },
//        { 103, "He fang", 'F', 92.5, 25 },
//        { 104, "Cheng ling", 'F', 87, 25 },
//        { 105, "Wang ming", 'M', 58, 25 }};
    
    struct stu boy[5] = {
    { 101, "Li ping", 'M', 45 },
    { 102, "Zhang ping", 'M', 62.5 },
    { 103, "He fang", 'F', 92.5 },
    { 104, "Cheng ling", 'F', 87 },
    { 105, "Wang ming", 'M', 58 }};

    int i = 0;
    int c = 0;
    float ave, s = 0;
    for (i = 0; i < 5; i++)
    {
        s += boy[i].score;    //计算总分
        if (boy[i].score < 60)
        {
            c += 1;        //统计不及格人的分数
        }
    }

    printf("s=%f\n", s);//打印总分数
    ave = s / 5;                    //计算平均分数
    printf("average=%f\ncount=%d\n\n", ave, c); //打印平均分与不及格人数


    for (i = 0; i < 5; i++)
    {
        printf(" name=%s,  score=%f\n", boy[i].name, boy[i].score);
           // printf(" name=%s,  score=%f\n", (boy+i)->name, (boy+i)->score);

    }

    
}

/**
 结构体套结构体
 */
void test4()
{
    struct coder tomwu = {1, "wutong", 'M'};
    printf("id: %d, name: %s, sex: %c \n", tomwu.id, tomwu.info.name, tomwu.info.sex);
    
    
    struct coder coderS[3] = {
        1, "wutong", 'M',
        2, "lipeng", 'M',
        3, "shuaige", 'M',
    };
    
    printf("结构体数组=======\n");
    for (int i = 0; i < 3; i++) {
        
        printf("id: %d, name: %s, sex: %c \n", coderS[i].id, coderS[i].info.name, coderS[i].info.sex);
    }
    
    
}

/**
 结构体相互赋值
 
 //相同类型的两个结构体变量，可以相互赋值
 //把s1成员变量的值拷贝给s2成员变量的内存
 //s1和s2只是成员变量的值一样而已，它们还是没有关系的两个变量
 */
void test5()
{
    struct coder tomwu = {1, "wutong", 'M'};

    struct coder lipeng;
    
    lipeng = tomwu;
    
    printf("tomwu:  id: %d, name: %s, sex: %c \n", tomwu.id, tomwu.info.name, tomwu.info.sex);
    printf("lipeng: id: %d, name: %s, sex: %c \n", lipeng.id, lipeng.info.name, lipeng.info.sex);
    
    
    lipeng.id = 90;
    
    printf("tomwu:  id: %d, name: %s, sex: %c \n", tomwu.id, tomwu.info.name, tomwu.info.sex);
    printf("lipeng: id: %d, name: %s, sex: %c \n", lipeng.id, lipeng.info.name, lipeng.info.sex);
}

/**
 
 结构体和指针
 
 1. 指向普通结构体变量的指针
 */
void test6(void)
{
    struct coder tomwu = {1, "wutong", 'M'};

    struct coder * p = &tomwu;
    
    printf("tomwu:  id: %d, name: %s, sex: %c \n", p->id, p->info.name, p->info.sex);
}

/**

结构体和指针

2. 堆区结构体变量
*/
void test7(void)
{
    struct coder * p = NULL;
    
    p = (struct coder *)malloc(sizeof(struct coder));
    
    p->id = 8;
    strcpy(p->info.name, "nihao");

//    p->info.sex = 'M';
    
    int value = 'M';
    memset(&(p->info.sex), value, sizeof(p->info.sex));
    
    printf("tomwu:  id-> %d, name-> %s, sex-> %c \n", p->id, p->info.name, p->info.sex);
    
    free(p);
    p = NULL;
    
    
}


/**
 
 结构体套一级指针
 */
void test8(void)
{
    struct iOSer *p = NULL;
    
    p = (struct iOSer *)malloc( sizeof(struct iOSer) );
    int valueSL = sizeof("ssss");
    int valueStrlen = strlen("test");
    
    printf(" valueSL = %d \n", valueSL);
    printf(" valueStrlen = %d \n", valueStrlen);
    
    p->name = malloc( sizeof("s") );
//    p->name = malloc( strlen("test") + 1 );
    
    
    p->age = 27;
    
    printf("p->name = %s, p->age=%d\n", p->name, p->age);
    printf("(*p).name = %s, (*p).age=%d\n", (*p).name, (*p).age);
    
    if (p->name != NULL)
    {
        free(p->name);
        p->name = NULL;
    }

    if (p != NULL)
    {
        free(p);
        p = NULL;
    }
}
void test9(void)
{
    struct coder iOSer = {99};
    printf("最初: iOSer.name = %d, iOSer.age=%s\n", iOSer.id, iOSer.info.name);
    
    test9a(iOSer);
    printf("最终: iOSer.name = %d, iOSer.age=%s\n", iOSer.id, iOSer.info.name);
}
/**
 值传递是无法修改返回的
 */
void test9a(struct coder iOSer)
{
    strcpy(iOSer.info.name, "tomwu");
    iOSer.id = 100;
    printf("函数里面: iOSer.name = %d, iOSer.age=%s\n", iOSer.id, iOSer.info.name);
}

/**

 结构体指针传递
 */
void test10(void)
{
    struct coder iOSer = {20};
    printf("最初: iOSer.name = %d, iOSer.age=%s\n", iOSer.id, iOSer.info.name);
    
    test10a(&iOSer);
    printf("最终: iOSer.name = %d, iOSer.age=%s\n", iOSer.id, iOSer.info.name);
}
/**
 
 结构体指针传递可以修改值
 */
void test10a(struct coder * iOSer)
{
    printf("函数里面刚进来: iOSer.name = %d, iOSer.age=%s\n", iOSer->id, iOSer->info.name);
    strcpy(iOSer->info.name, "yaojun");
    iOSer->id = 30;
    
    printf("函数里面修改后: iOSer.name = %d, iOSer.age=%s\n", iOSer->id, iOSer->info.name);
}


void test11(void)
{
    struct coder iOSers[3] = {20};
    int i = 0;
    int n = sizeof(iOSers) / sizeof( iOSers[0] );
    
    
    
    for (i = 0; i < n; i++) {
        struct coder iOSer = iOSers[i];
        printf(" 最初每个数组 iOSer.name = %d, iOSer.age=%s\n", iOSer.id, iOSer.info.name);
    }
    
    printf("==== \n");
    
    test11a(iOSers, n);
    
    for (i = 0; i < n; i++) {
        struct coder iOSer = iOSers[i];
        printf(" 函数修改后每个数组 iOSer.name = %d, iOSer.age=%s\n", iOSer.id, iOSer.info.name);
    }
    
    printf("==== \n");
}

void test11a(struct coder * iOSer, int count)
{
    
    for (int i = 0; i < count; i++) {
        /**
         字符串赋值格式化函数
         */
        sprintf(iOSer->info.name, "name%d%d%d", i, i, i);
        iOSer->id = 20 + i;
        iOSer++;
    }
    
    
}


void test12(void)
{
    struct coder iOSer = {12, "wahaha", 'M'};
    
    printf("函数外: id: %d, name: %s, sex: %c \n", iOSer.id, iOSer.info.name, iOSer.info.sex);
    
    test12b(&iOSer);
    
    iOSer.id = 33;
    printf("函数外,调用函数后: id: %d, name: %s, sex: %c \n", iOSer.id, iOSer.info.name, iOSer.info.sex);
    
    
}

void test121(struct coder * iOSerP)
{
    printf("函数内1: id->: %d, name->: %s, sex->: %c \n", iOSerP->id, iOSerP->info.name, iOSerP->info.sex);
    
    // 可以置空, 但是从这一句以后呢,就不可再做访问了
    iOSerP = NULL;
    printf("函数内2: id->: %d, name->: %s, sex->: %c \n", iOSerP->id, iOSerP->info.name, iOSerP->info.sex);
}
void test12a(struct coder * const iOSerP)
{
    printf("函数内1: id->: %d, name->: %s, sex->: %c \n", iOSerP->id, iOSerP->info.name, iOSerP->info.sex);
    
//    不能置为NULL
//    iOSerP = NULL;
    
    // 可以修改值, 但是不可以置NULL
    iOSerP->id = 14;
    strcpy(iOSerP->info.name, "xuebi");
    printf("函数内2: id->: %d, name->: %s, sex->: %c \n", iOSerP->id, iOSerP->info.name, iOSerP->info.sex);
}

void test12b(const struct coder * iOSerP)
{
    printf("hi \n");
    iOSerP = NULL; // ok
//    iOSerP->id = 0; // 错误
}

void test12c(const struct coder * const iOSerP)
{
    printf("hi \n");
//    iOSerP = NULL; // 错误
//    iOSerP->id = 0; // 错误
}


/**
 枚举
 */
void test13(void)
{
    printf("%d \n", mon);
    
    
}




/**
 typedef
 */
void test14(void)
{
    IOSCoder iOSer = {12, "wahaha", 'M'};
    
    printf("id: %d, name: %s, sex: %c \n", iOSer.id, iOSer.info.name, iOSer.info.sex);
    
    Student stu = {"zhangsan", 26};
    printf("name: %s, age = %d \n", stu.name, stu.age);
    
    struct Student stu2 = {"lisi", 20};
    printf("stu2--: name: %s, age = %d \n", stu2.name, stu2.age);
    
}
void test15(void)

{
    
}
void test16(void)

{
    
}
