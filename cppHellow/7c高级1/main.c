//
//  main.c
//  7c高级1
//
//  Created by codew on 8/12/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>


void test1(void);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char buf[3] = "abc";
    
//    buf = NULL;
    
    printf("%c \n", *(buf+2));
    
    printf("buf:%s\n", buf);
    
    test1();
    
    return 0;
}


/**
 c中const局部
 */

void test1(void)
{
    const  int  constA = 10;

    int* p = (int*)&constA;

    *p = 300;

    printf("constA:%d\n",constA);

    printf("*p:%d\n", *p);
}


