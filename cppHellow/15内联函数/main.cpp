//
//  main.cpp
//  15内联函数
//
//  Created by codew on 8/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

void test1(void);
void test2(void);
void test3(void);
void test4(void);
void test5(void);

#define ADD(x,y) x+y

inline  int  Add(int x,int y){

 return x + y;

}


#define COMPARE(x,y) ((x) < (y) ? (x) : (y))

int Compare(int x,int y){

 return x < y ? x : y;

}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test2();
    
    return 0;
}


void test1(void)
{
    int ret1 = ADD(10, 20) * 10; //希望的结果是300

    int ret2 = Add(10, 20) * 10; //希望结果也是300

    cout << "ret1:" << ret1 << endl; //210

    cout << "ret2:" << ret2 << endl; //300
}


void test2(void)
{
    int a = 1;

    int b = 3;

     cout << "COMPARE(++a, b):" << COMPARE(++a, b) << endl; // 3
    
    
    

    //cout << "Compare(int x,int y):" << Compare(++a, b) << endl; //2
}
