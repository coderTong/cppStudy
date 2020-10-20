//
//  main.cpp
//  102格式化输出
//
//  Created by codew on 10/20/20.
//  Copyright © 2020 codertom. All rights reserved.
/**
 4.4.2.2 控制符格式化输出

 C++提供了在输入输出流中使用的控制符(有的书中称为操纵符)。
 */

#include <iostream>

#include <iomanip>
using namespace std;

void test01()
{
    int number = 99;
    
    cout.width(20); // 设置宽度
    cout.fill('*'); // 填充
    cout.setf(ios::left); // 让数据在左边
    
    cout.unsetf(ios::dec); // 卸载10进制
    cout.setf(ios::hex); // 安装十六进制
    cout.setf(ios::showbase); // 显示基数
    
    cout.unsetf(ios::hex); // 卸载十六进制
    cout.setf(ios::oct); // 安装八进制
    
    cout << number << endl;
    
}

// 通过控制符 来格式化输出
void test02()
{
    int number = 99;
    
    cout << setw(20)
    << setfill('~')
    << setiosflags(ios::showbase)
    << setiosflags(ios::right)
    << hex
    << number
    << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test02();
    return 0;
}
