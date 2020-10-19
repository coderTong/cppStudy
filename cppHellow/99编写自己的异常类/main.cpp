//
//  main.cpp
//  99编写自己的异常类
//
//  Created by codew on 10/20/20.
//  Copyright © 2020 codertom. All rights reserved.
//

/**
 ① 标准库中的异常是有限的；

 ② 在自己的异常类中，可以添加自己的信息。（标准库中的异常类值允许设置一个用来描述异常的字符串）。

 2. 如何编写自己的异常类？

 ① 建议自己的异常类要继承标准异常类。因为C++中可以抛出任何类型的异常，所以我们的异常类可以不继承自标准异常，但是这样可能会导致程序混乱，尤其是当我们多人协同开发时。

 ② 当继承标准异常类时，应该重载父类的what函数和虚析构函数。

 ③ 因为栈展开的过程中，要复制异常类型，那么要根据你在类中添加的成员考虑是否提供自己的复制构造函数。
 */

#include <iostream>

using namespace std;

//class MyOutOfRange : public exception
//{
//public:
//    MyOutOfRange(const string errorInfo)
//    {
//        this->m_Error = errorInfo;
//    }
//
//    MyOutOfRange(const char * errorInfo)
//    {
//        this->m_Error = string(errorInfo);
//    }
//
//    virtual ~MyOutOfRange()
//    {
//
//    }
//
//    virtual const char * what() const
//    {
//        return this->m_Error.c_str();
//    }
//
//    string m_Error;
//};
//
//class Person
//{
//public:
//    Person(int age)
//    {
//        if (age <= 0 || age > 150) {
//
//            throw  MyOutOfRange("我的异常, 年龄必须 在 0~150 之间");
//        }else{
//
//            this->m_Age = age;
//        }
//    }
//
//    int m_Age;
//};
//
//void test01()
//{
//    try {
//        Person p(151);
//    } catch (out_of_range & e) {
//
//        cout << e.what() << endl;
//    } catch (length_error & e){
//
//        cout << e.what() << endl;
//    } catch (MyOutOfRange & e){
//
//        cout << e.what() << endl;
//    }
//}

class MyOutOfRange:public std::exception
{
public:
    MyOutOfRange(const string  errorInfo)
    {
        this->m_Error = errorInfo;
    }

    MyOutOfRange(const char * errorInfo)
    {
        this->m_Error = string( errorInfo);
    }

    virtual  ~MyOutOfRange()
    {
    
    }
    virtual const char* what() const noexcept override
//    virtual const char *  what() const
    {
        return this->m_Error.c_str() ;
    }

    string m_Error;

};

class Person
{
public:
    Person(int age)
    {
        if (age <= 0 || age > 150)
        {
            //抛出异常 越界
            //cout << "越界" << endl;
            //throw  out_of_range("年龄必须在0~150之间");

            //throw length_error("长度异常");
            throw MyOutOfRange(("我的异常 年龄必须在0~150之间"));
        }
        else
        {
            this->m_Age = age;
        }
        
    }

    int m_Age;
};


void test01()
{
    try
    {
        Person p(151);
    }
    catch ( out_of_range & e )
    {
        cout << e.what() << endl;
    }
    catch (length_error & e)
    {
        cout << e.what() << endl;
    }
    catch (MyOutOfRange e)
    {
        cout << e.what() << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test01();
    return 0;
}
