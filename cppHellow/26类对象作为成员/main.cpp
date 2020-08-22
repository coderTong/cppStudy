//
//  main.cpp
//  26类对象作为成员
//
//  Created by codew on 8/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

//汽车类

class  Car{

public:

 Car(){
 cout << "Car 默认构造函数!" << endl;
 mName = "大众汽车";
 }

 Car(string name){

 cout << "Car 带参数构造函数!" << endl;

 mName = name;

 }

 ~Car(){

 cout << "Car 析构函数!" << endl;

 }

public:
  string  mName;

};

//拖拉机

class  Tractor{

public:

 Tractor(){

 cout << "Tractor 默认构造函数!" << endl;

 mName = "爬土坡专用拖拉机";

 }

 Tractor(string name){

 cout << "Tractor 带参数构造函数!" << endl;

 mName = name;

 }

 ~Tractor(){

 cout << "Tractor 析构函数!" << endl;

 }

public:

  string  mName;

};

//人类

class  Person{

public:

#if 0

  //类mCar不存在合适的构造函数

 Person(string name){

 mName = name;

 }

#else

  //初始化列表可以指定调用构造函数

 Person(string carName, string tracName, string name) : mTractor(tracName), mCar(carName), mName(name){

 cout << "Person 构造函数!" << endl;

 }

#endif

  void  GoWorkByCar(){

 cout << mName << "开着" << mCar.mName << "去上班!" << endl;

 }

  void  GoWorkByTractor(){

 cout << mName << "开着" << mTractor.mName << "去上班!" << endl;

 }

 ~Person(){

 cout << "Person 析构函数!" << endl;

 }

private:

  string  mName;

  Car  mCar; //编译只能调用无参的构造

  Tractor  mTractor;

};

void test(){

  Person person("宝马", "东风拖拉机", "赵四");

// Person person("刘能");

 person.GoWorkByCar();

 person.GoWorkByTractor();

}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test();
    
    return 0;
}
