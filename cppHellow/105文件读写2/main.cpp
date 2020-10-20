//
//  main.cpp
//  105文件读写2
//
//  Created by codew on 10/20/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>
#include <fstream>

using namespace std;

// 把程序中的 信息输出 到 缓冲区 , 然后写到文件( 写文件)
void test01()
{
    // 定义流对象
    ofstream ofs;
    
    // 打开文件, 以写的方式打开, 如果没有文件, 就创建
    ofs.open("test.txt", ios::out | ios::trunc);
    
    // 判断是否打开成功
    if ( !ofs.is_open()) {
        
        cout << "打开失败" << endl;
    }
    
    // 写信息
    ofs << "姓名: 狂铁" << endl;
    ofs << "年龄: 11" << endl;
    ofs << "身高: 180cm" << endl;
    
    // 关闭文件
    ofs.close(); // 关闭文件, 并刷新缓冲区
}

// 把磁盘信息 输入到 缓冲区 , 然后读到程序中 (读文件)
void test02()
{
    ifstream ifs;
    
    ifs.open("test.txt", ios::in);
    if ( ifs.is_open() == false) {
        cout << "打开失败" << endl;
    }
    
    // 第一种 方式 读取 文件
    /**
     2020年10月20日15:01:33
     Hello, World!
     姓名:
     狂铁
     年龄:
     11
     身高:
     180cm
     
     Program ended with exit code: 0
     */
    char buf[1024] = {0};
//    while (ifs >> buf) {
//
//        cout << buf << endl;
//    }
    
    // 第二种方式读文件
    // 一行一行 读取
    /**
     Hello, World!
     姓名: 狂铁
     年龄: 11
     身高: 180cm
     */
//    while ( !ifs.eof() ) { // 判断是否读到 文件尾部
//
//        ifs.getline(buf, sizeof(buf));
//        cout << buf << endl;
//    }

    // 第三种方式读取文件
    // 单个字符读取
    /**
     2020年10月20日15:04:30 
     Hello, World!
     姓名: 狂铁
     年龄: 11
     身高: 180cm
     */
    char c;
    while ( ( c=ifs.get() ) != EOF) {

        cout << c;
    }
    
    // 关闭文件
    ifs.close();
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test02();
    
    system("pwd");
    
    return 0;
}
