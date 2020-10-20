//
//  main.cpp
//  103文件读写
//
//  Created by codew on 10/20/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <fstream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    char* sourceFileName = "/Users/codew/Desktop/T/a.txt";
    char* targetFileName = "/Users/codew/Desktop/T/b.txt";
    
    // 创建文件输入流 对象
    ifstream ism(sourceFileName, ios::in);
    
    ofstream osm(targetFileName, ios::out);
    
    if ( !ism ) {
        
        cout << "文件打开 失败!" << endl;
    }
    
    while ( !ism.eof()) {
        
        char buf[1024] = {0};
        ism.getline(buf, 1024);
        
        cout << buf << endl;
        osm << buf << endl;
    }
    
    ism.close();
    osm.close();
    
    system("pwd");
    
    return 0;
}
