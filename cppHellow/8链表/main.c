//
//  main.c
//  8链表
//
//  Created by codew on 8/12/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _Stu{
   
    int id;    //数据域
    char name[100];
    struct _Stu *next; //指针域
}Stu;

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);

void test6(void);
void test7(void);
void test8(void);
void test9(void);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    test2();
    return 0;
}

/**
 静态链表
 */
void test1(void)
{
    //初始化三个结构体变量
    Stu s1 = { 1, "yuri", NULL };
    Stu s2 = { 2, "lily", NULL };
    Stu s3 = { 3, "lilei", NULL };

    s1.next = &s2; //s1的next指针指向s2
    s2.next = &s3;
    s3.next = NULL; //尾结点

    Stu *p = &s1;
    while (p != NULL)
    {
        printf("id = %d, name = %s\n", p->id, p->name);

        //结点往后移动一位
        p = p->next;
    }
    
}


/**
 
 动态链表
 */
void test2(void)
{
    
    // 动态分配3个节点
    
    Stu * s1 = (Stu *)malloc( sizeof(Stu) );
    s1->id = 1;
    strcpy(s1->name, "wt");
    
    Stu * s2 = (Stu *)malloc( sizeof(Stu) );
    s2->id = 2;
    strcpy(s2->name, "yj");
    
    Stu * s3 = (Stu *)malloc( sizeof(Stu) );
    s3->id = 3;
    strcpy(s3->name, "phm");
    
    
    s1->next = s2;
    s2->next = s3;
    s3->next = NULL;
    

    Stu * p = s1;
    while ( p != NULL) {
        
        
        printf("id = %d, name = %s \n", p->id, p->name);
        
        p = p->next;
    }
    
    
    
    p = s1;
    Stu * tmp = NULL;

    while (p != NULL) {
        
        tmp = p;
        p = p->next;
        
        free(tmp);
        tmp = NULL;
    }
    
}
