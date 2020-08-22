//
//  main.cpp
//  25初始化列表
//
//  Created by codew on 8/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class  Person{

public:

#if 0

  //传统方式初始化

 Person(int a,int b,int c){

 mA = a;

 mB = b;

 mC = c;

 }

#endif

  //初始化列表方式初始化

 Person(int a, int b, int c):mA(c),mB(b),mC(a){}

  void  PrintPerson(){

 cout << "mA:" << mA << endl;

 cout << "mB:" << mB << endl;

 cout << "mC:" << mC << endl;

 }

private:

 int mA;

 int mB;

 int mC;

};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    
    Person p1 = Person(3, 4, 5);
    p1.PrintPerson();
    
    
    
    return 0;
}
