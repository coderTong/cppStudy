//
//  main.cpp
//  30deleteVoid星
//
//  Created by codew on 8/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class  Person{

public:
    
    // 如果没有无参构造的话
    Person(){
        cout << "无参构造函数调用~" << endl;
        pName = (char*)malloc(sizeof("meiyouname"));
        strcpy(pName,"meiyouname");
        mAge = 0;
       
    }

 Person(char* name, int age){

     cout << "有参构造函数调用~" << endl;
     pName = (char*)malloc(sizeof(name));

     strcpy(pName,name);

     mAge = age;
    
 }

 ~Person(){

     cout << "析构函数调用~" << endl;
     
     if (pName != NULL){

         delete pName;

     }

 }

public:

 char* pName;

 int mAge;

};

void test(){
    
    // 用 void* 去接的话, 用delete的话不会去调用析构函数
//    void* person = new Person("john",20);
//    Person* person = new Person("john",20);
//    delete person;
    
    
    // =========================================================================================================
    /**
     以上代码有什么问题吗？(vs下直接中断、qt下析构函数调用一次)

     使用了new也搭配使用了delete，问题在于Person有10个对象，那么其他9个对象可能没有调用析构函数，也就是说其他9个对象可能删除不完全，因为它们的析构函数没有被调用。
     */
    
    // 如果没有无参构造的话 下面这句直接报错
    Person* person = new Person[10];
    // 只会调用一个对象的析构函数, 编译不会报错, 运行一个对象的析构函数后报错
//    delete  person;
    // 这样的话就毛得问题了
    //如果在new表达式中使用[]，必须在相应的delete表达式中也使用[].如果在new表达式中不使用[], 一定不要在相应的delete[]表达式中使用[].

    delete[]  person;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test();
    
    
    return 0;
}
