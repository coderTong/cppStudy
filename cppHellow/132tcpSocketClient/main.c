//
//  main.c
//  132tcpSocketClient
//
//  Created by codew on 12/3/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <stdio.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");


    // 1. 创建套接字
    int my_socket_fd;
    my_socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 2. 连接服务器
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9986);
    inet_pton(AF_INET, "155.138.132.36", &addr.sin_addr.s_addr);
//    inet_pton(AF_INET, "192.168.31.147", &addr.sin_addr.s_addr);
//    connect(<#int#>, <#const struct sockaddr *#>, <#socklen_t#>)
    connect(my_socket_fd, (struct sockaddr *)&addr, sizeof(addr) );

    // 3. 读写数据

    char buf[1024] = "";
    while (1)
    {
        bzero(buf, sizeof(buf));
        int n;

        // 一直给服务器发消息
        n = read(STDIN_FILENO, buf, sizeof(buf));
        // 发送数据给服务器
        write(my_socket_fd, buf, n);

        // 从服务端一直读
        n = read(my_socket_fd, buf, sizeof(buf));
        write(STDOUT_FILENO, buf, n);

    }

    // 4. 关闭套接字
    close(my_socket_fd);

    return 0;
}



