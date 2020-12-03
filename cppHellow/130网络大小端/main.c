//
//  main.c
//  130网络大小端
//
//  Created by codew on 12/2/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    unsigned char buf[4] = {192,168,32,9};
    
    unsigned int num  = *(int *)buf;
    // 小端-->大端 ip转
    unsigned int sum = htonl(num);
    unsigned char *p = &sum;
    
    printf("%d %d %d %d\n", *p, *(p+1), *(p+2), *(p+3));
    
    // 小端-->大端 转端口
    unsigned short port = 0x102;
    unsigned short nPort = htons(port);
    
    printf("%x\n", nPort);
    
    return 0;
}
