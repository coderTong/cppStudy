//
//  main.cpp
//  cppHellow
//
//  Created by codew on 7/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>
#include "NameTest.h"

//using namespace::std; // 标准命名空间

using namespace std;

namespace myName {

    int wohaha = 90;
    int maidong = 100;
}



// 可以嵌套
namespace myNameSuper {

    int zhoujielun = 45;

    namespace zhouzhou{

       int nibaba;
       int wocao = 666;

    }

}

using namespace myName;
using namespace myNameSuper;

namespace myNameSuper {

int zhouxingci = 909;
}

void test01()
{
    cout << "zhouxingci \n " << zhouxingci << endl;
}


// 命名空间取别名看看
void test002()
{
    // 前面是新名字   后面是旧名字
    namespace wodeSuper = myNameSuper;
    
    cout << wodeSuper::zhouxingci;
}



// 匿名命名空间

namespace {

double pi = 0.001;

}


int main(int argc, const char * argv[]) {
    
    // cout 是标准输出流对象, 打印字符串
    // endl 是刷新缓冲区, 并换行
    // insert code here...
    cout << "Hello, World!\n" << endl;
    
    system("别瞎搞!");
    
    printf("c 的打印 \n");
    
    printf("%d \n", myName::wohaha);
    
    printf("%d \n", wohaha);
    
    
    cout << "wohaha 等于" << wohaha << endl;
    
    string wodeStr = "今天星期几?";
    
    cout << "wodeStr : " << wodeStr << endl;
    
    
    myNameTest1::funcOne1();
    
    test01();
    
    cout << "匿名命名空间 pi" << ::pi << endl;
    
    // 访问嵌套的
    
    cout << "我在访问嵌套命名空间里的值: " << myNameSuper::zhouzhou::wocao << endl;
    
    myNameTest1::valueHaHa = 90;
    cout << "我再看看" << myNameTest1::valueHaHa << endl;
    
    return 0;
}
