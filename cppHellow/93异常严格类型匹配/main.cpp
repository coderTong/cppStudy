//
//  main.cpp
//  93异常严格类型匹配
//
//  Created by codew on 10/19/20.
//  Copyright © 2020 codertom. All rights reserved.
//

/**
 3.2.2 异常严格类型匹配

 异常机制和函数机制互不干涉,但是捕捉方式是通过严格类型匹配。
 */

#include <iostream>

using namespace std;

void TestFunction()
{
    
    cout << "开始抛出异常....." << endl;
    
//    throw 10;
//    throw 'a';
//    throw "ABCD";
    
    string ex = "string exception!";

    throw ex;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    try {
        TestFunction();
    } catch (int) {
        
        cout << "抛出 int 类型异常!" << endl;
    } catch (char) {
        
        cout << "抛出 char 类型异常!" << endl;
    } catch (char*) {
        
        cout << "抛出char* 类型异常!" << endl;
    } catch (string) {
        
        cout << "抛出 string 类型异常!" << endl;
    } catch (...) {// 捕获所有异常
        
        cout << "抛出 其他 类型异常!" << endl;
    }
    
    return 0;
}
