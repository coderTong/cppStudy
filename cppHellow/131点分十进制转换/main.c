//
//  main.c
//  131点分十进制转换
//
//  Created by codew on 12/3/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>

#include <arpa/inet.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    unsigned char buf[] = "192.168.31.4";
    unsigned int num = 0;
    inet_pton(AF_INET, buf, &num);
    unsigned char * p = (unsigned char *)&num;
    printf("%d %d %d %d\n", *p, *(p+1), *(p+2), *(p+3));
    
    //
//    char ip[16] = "";
//    inet_ntop(AF_INET, &num, ip, 16);
    
    // 12 + 3 = 15, \0  ====> 15 + 1 = 16;
    "255.255.255.255";
    
    INET6_ADDRSTRLEN;
    char ip[INET_ADDRSTRLEN] = "";
    inet_ntop(AF_INET, &num, ip, INET_ADDRSTRLEN);
    
    
    printf("%s\n", ip);
    
    return 0;
}
