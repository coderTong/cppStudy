//
//  main.cpp
//  100标准输入流
//
//  Created by codew on 10/20/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 标准输入流对象cin，重点掌握的函数

 cin.get() //一次只能读取一个字符

 cin.get(一个参数) //读一个字符

 cin.get(两个参数) //可以读字符串

 cin.getline()

 cin.ignore()

 cin.peek()

 cin.putback()
 */


// cin.get
void test01()
{
#if 0
//    char ch = cin.get();
//    cout << ch << endl;
//
//    cin.get(ch);
//    cout << ch << endl;
    
    char c1, c2, c3, c4;
    cin.get(c1).get(c2).get(c3).get(c4);
    
    cout << c1 << " " << c2 << " " << c3 << " " << c4 << " ";
    
#endif
    /**
     Hello, World!
     adfsgassasfhafhafshwsfhascbfgsdgddgsagsafhwhahsashrwgrrgwrqr
     adfsgassaProgram ended with exit code: 0
     */
    char buf[10] = {0};
    cin.getline(buf, 10);
    
    cout << buf;
}

// cin.ignore
void test02()
{
    char buf[1024] = {0};
    cin.ignore(4); // 忽略缓冲区当前字符 参数表示前面 几个
    
    cin.get(buf, 1024);
    cout << buf << endl;
}

// cin.putback 将数据 放回缓冲区
void test03()
{
    // 从缓冲区 取走一个字符
    char ch = cin.get();
    cout << "从缓冲区 取走的字符 :" << ch << endl;
    
//    // 将数据再放回 缓冲区
    cin.putback(ch);
    char buf[1024] = {0};
    
    cin.get(buf, 1024);
    cout << buf << endl;
}

// cin.peek 偷窥, 或者叫秋一眼, 与上面的比较是上面是拿了, 这个就是瞅一眼
void test04()
{
    
    // 偷窥下 缓冲区的数据
    char ch = cin.peek();
    
    cout << "偷窥 缓冲区数据: " << ch << endl;
    char buf[1024] = {0};
    
    cin.get(buf, 1024);
    cout << buf << endl;
}

// 练习
void test05()
{
    cout << "请输入一个数字或者 字符串:" << endl;
    char ch = cin.peek();
    
    if ( ch >= '0' && ch <= '9') {
        
        int number;
        cin >> number;
        cout << "数字: " << number << endl;
    }else{
        
        char buf[64] = {0};
        cin.getline(buf, 64);
        cout << "字符串: " << buf << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test05();
    
    return 0;
}
