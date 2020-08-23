//
//  main.cpp
//  38const修饰对象
//
//  Created by codew on 8/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person{

public:
    Person(){
        this->mAge = 0;
        this->mID = 0;
    }

    //在函数括号后面加上const,修饰成员变量不可修改,除了mutable变量
    void changeTest1() const{

        printf("%s\n", __func__);

        mID = 10;
//        mAge = 100;
    }


    void showPerson(){

        printf("%s\n", __func__);
        cout << "ID: " << mID << " mAge:" << mAge << endl;
    }


public:
    mutable int qnmb;
    int mAge;
    mutable int mID;
    const int tieHanHan = 88;
};




//class  Person{
//
//public:
//
// Person(){
//
//     this->mAge = 0;
//     this->mID = 0;
// }
//
//  void  ChangePerson() const{
//
//// mAge = 100;
//
//      mID = 100;
//
// }
//
//  void  ShowPerson(){
//
//      cout << "ID:" << this->mID << " Age:" << this->mAge << endl;
//
// }
//
//public:
//    int mAge;
//    mutable  int  mID;
//
//};
//
//void test(){
//
//    const Person person;
//
//    //1\. 可访问数据成员
//    cout << "Age:" << person.mAge << endl;
//
//  //person.mAge = 300; //不可修改
//
// person.mID = 1001; //但是可以修改mutable修饰的成员变量
//
//  //2\. 只能访问const修饰的函数
//
//  //person.ShowPerson();
//
// person.ChangePerson();
//
//}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
//    test();
    const Person person;

     //1\. 可访问数据成员

    cout << "Age:" << person.mAge << endl;

//     person.mAge = 300; //不可修改

    person.mID = 1001; //但是可以修改mutable修饰的成员变量
//    person.tieHanHan = 110; //NO

     //2\. 只能访问const修饰的函数

//     person.showPerson();

    person.changeTest1();
    
    
    
    
    Person sb;
    sb.mID = 3838438;
    sb.showPerson();
    
    return 0;
}
