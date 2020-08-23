//
//  main.cpp
//  34单例模式
//
//  Created by codew on 8/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Printer{
  
public:
    static Printer*getInstance()
    {
        printf("%s\n", __func__);
        return pPrinter;
    }
    
    void printText(string text){
        
        cout << "打印内容:" << text << endl;
        cout << "已打印次数:" << mTimes << endl;
        cout << "--------------" << endl;
        mTimes++;
    }
    
private:
    Printer(){mTimes = 0;}
    Printer(const Printer&){}
    
private:
    static Printer * pPrinter;
    int mTimes;
};

Printer * Printer::pPrinter = new Printer;


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    Printer * printer = Printer::getInstance();
    
    printer->printText("离职报告!");
    printer->printText("入职合同!");
    printer->printText("提交代码!");
    
    return 0;
}
