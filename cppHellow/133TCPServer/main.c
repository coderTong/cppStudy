//
//  main.c
//  133TCPServer
//
//  Created by codew on 12/4/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>

#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    // 1. 创建套接字
    int serverSock = socket(AF_INET, SOCK_STREAM, 0);
    // 2. bind绑定端口ip
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9986);
//    inet_pton(AF_INET, "192.168.31.147", &addr.sin_addr.s_addr);
    inet_pton(AF_INET, "155.138.132.36", &addr.sin_addr.s_addr);
    
    bind(serverSock, (struct sockaddr *)&addr, sizeof(addr));
        
    // 3. listen 创建两个队列 将套接字由主动变被动
    listen(serverSock, 128);
    
    // 4. accept 将完成握手的连接提取出来
    struct sockaddr_in cliaddr;
    socklen_t len = sizeof( cliaddr );
    int cfd = accept(serverSock, (struct sockaddr *)&cliaddr, &len);
   
    char ip[INET_ADDRSTRLEN] = "";
    // 打印一下提取到的完成连接的socket
    printf("new client  ip=%s, port=%d\n",
           inet_ntop(AF_INET, &cliaddr.sin_addr.s_addr, ip, INET_ADDRSTRLEN),
           ntohs(cliaddr.sin_port) );
    
    // 读写
    char buf[1024] = "";
    while (1) {
        int n;
        
        // 读取客户端发过来的数据
        n = read(cfd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, n);
        
        // 发送数据给客户端
        n = read(STDIN_FILENO, buf, sizeof(buf));
        write(cfd, buf, n);
    }
    
    // 关闭
    close(serverSock);
    close(cfd);
    
    return 0;
}

