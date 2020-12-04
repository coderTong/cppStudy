//
//  main.c
//  130网络大小端
//
//  Created by codew on 12/2/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>
#include <arpa/inet.h>

void test0();
void test1();

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    /**
     网络里面都应该定义无符号 的
     */
    test0();
    
    return 0;
}

/**
 网络转主机
 大端转小端
 */
void test1()
{
    unsigned char buf[4] = {9,23,168,192};
    
    unsigned int num  = *(int *)buf;
    // 小端-->大端 ip转
    unsigned int sum = ntohl(num);
    unsigned char *p = (unsigned char *)&sum;
    
    printf("%d %d %d %d\n", *p, *(p+1), *(p+2), *(p+3));
    
    // 小端-->大端 转端口
    unsigned short port = 0x102;
    unsigned short nPort = ntohs(port);
    
    printf("%x\n", nPort);
}


/**
 主机转网络
 小端转大端
 */
void test0()
{
    unsigned char buf[4] = {192,168,32,9};
    
    unsigned int num  = *(int *)buf;
    // 小端-->大端 ip转
    unsigned int sum = htonl(num);
    unsigned char *p = (unsigned char *)&sum;
    
    printf("%d %d %d %d\n", *p, *(p+1), *(p+2), *(p+3));
    
    // 小端-->大端 转端口
    unsigned short port = 0x102;
    unsigned short nPort = htons(port);
    
    printf("%x\n", nPort);
}
