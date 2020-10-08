//
//  main.cpp
//  85类模板头文件和源文件分离
//
//  Created by codew on 10/5/20.
//  Copyright © 2020 codertom. All rights reserved.
// 2020年10月06日10:48:41


/**
 
 结论: 案例代码在qt编译器顺利通过编译并执行，但是在Linux和vs编辑器下如果只包含头文件，那么会报错链接错误，需要包含cpp文件，但是如果类模板中有友元类，那么编译失败！

 解决方案: 类模板的声明和实现放到一个文件中，我们把这个文件命名为.hpp(这个是个约定的规则，并不是标准，必须这么写).

 原因：

 类模板需要二次编译，在出现模板的地方编译一次，在调用模板的地方再次编译。

 C++编译规则为独立编译。
 */

#include <iostream>

using namespace std;

#include <string>
#include "Person.hpp"

// 模板 二次 编译

// 编译器 编译源码 逐个编译 单元 编译的

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Person<string, int> p("nibb", 20);
    p.showPerson();
    
    return 0;
}
