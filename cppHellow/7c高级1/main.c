//
//  main.c
//  7c高级1
//
//  Created by codew on 8/12/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    char buf[3] = "abc";
    
//    buf = NULL;
    
    printf("%c \n", *(buf+2));
    
    printf("buf:%s\n", buf);
    
    
    return 0;
}
