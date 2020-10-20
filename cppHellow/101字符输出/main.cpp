//
//  main.cpp
//  101字符输出
//
//  Created by codew on 10/20/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>
/**
 cout.flush() //刷新缓冲区 Linux下有效

 cout.put() //向缓冲区写字符

 cout.write() //从buffer中写num个字节到当前输出流中。
 */

using namespace std;

// cout.flush 刷新缓冲区，linux下有效
void test01()
{
    cout << "cout.flush() come come ...";
    // 刷新 缓冲区
    cout.flush();
}

// cout.put 输出一个 字符
void test02()
{
    cout.put('a');
    // 链式编程
    cout.put('h').put('e').put('l').put('\n');
}

// cout.write 输出 字符 串 buf, 输出多少个
void test03()
{
//    char*str = "sb";
//    cout.write(str, strlen(str));
    
//    cout << "个数: " << strlen(str);
    
    char*str = "**********";
//    for (int i = 1; i <= strlen(str); i++) {
//        
//        cout.write(str, i);
//        cout << endl;
//    }
    
    for (int i = strlen(str); i > 0; i--) {

        cout.write(str, i);
        cout << endl;
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test03();
    return 0;
}
