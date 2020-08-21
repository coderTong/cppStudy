//
//  main.c
//  13const
//
//  Created by codew on 8/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    const  int  constA = 10;

    int* p = (int*)&constA;

    *p = 300;

    printf("constA:%d\n",constA);

    printf("*p:%d\n", *p);
    
    
    return 0;
}



