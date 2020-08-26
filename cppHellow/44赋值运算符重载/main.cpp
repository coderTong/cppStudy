//
//  main.cpp
//  44赋值运算符重载
//
//  Created by codew on 8/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
    
    friend ostream& operator<<(ostream& os, const Person& person)
    {
        os << "ID: " << person.mID << " Age:" << person.mAge << endl;
        return os;
    }
    
public:
    
    Person(int id, int age){
        
        cout << "Person 有参构造函数: " << __func__ << endl;
        
        this->mID = id;
        this->mAge = age;
    }
    
    Person(const Person& person)
    {
        cout << "拷贝构造函数, 进来了???" << endl;
        this->mID = person.mID;
        this->mAge = person.mAge;
    }
    
    // 重载赋值运算符
    Person& operator=(const Person& person){
        
        cout << "Person 重载赋值运算符: " << __func__ << endl;
        
        this->mID = person.mID;
        this->mAge = person.mAge;
        
        return *this;
    }
    
    
private:
    int mID;
    int mAge;
};



// 1. =号混淆的地方
void test01(){
    
    Person person1(10, 20);
    // 调用拷贝构造
    Person person2 = person1;
    
    // 如果一个对象还没有被创建, 则必须初始化, 也就是调用构造函数
    // 上述例子由于 person2 还没有初始化, 所以会调用构造函数
    // 由于person2是从已有的person1来创建的, 所以只有一个选择
    // 就是调用拷贝构造函数
    
    // 调用operator=函数
    person2 = person1;
    // 由于person2已创建, 不需要调用构造函数, 这时候调用的是重载的赋值运算符
}

// 2. 赋值重载案例
void test02()
{
    Person person1(26, 29);
    Person person2(20, 20);
    
    cout << "person1: " << person1;
    cout << "person2: " << person2;
    
    person2 = person1;
    
    cout << "person2: " << person2;
}


// 常见错误, 当准备给 两个相同对对象 赋值时,  应该首先检查一下 这个对象 是否 对自身 赋值了
// 对于本例来讲,  无论如何 执行这些赋值运算 都是无害的,  但如果对类的实现进行修改, 那么将会出现差异

// 3. 类中指针

class Person2 {
    
    friend ostream& operator<<(ostream& os, const Person2& person)
    {
        os << "Name: " << person.pName << " ID:" << person.mID << " Age:" << person.mAge << endl;
        
        return os;
    }
    
public:
    Person2(char* name, int id, int age){
        
        cout << "Person2的有参构造函数: " << __func__ << endl;
        
        this->pName = new char[ strlen(name) + 1];
        strcpy(this->pName, name);
        
        this->mID = id;
        this->mAge = age;
        
    }
    
#if 1
    
    // 重载 赋值运算符
    Person2& operator=(const Person2& person){
        
        cout << "Person2的重载 赋值运算符: " << __func__ << endl;
        
        if (this->pName  != NULL) {
            
            delete [] this->pName;
        }
        
        this->pName = new char[ strlen(person.pName) + 1];
        
        strcpy(this->pName, person.pName);
        
        this->mID = person.mID;
        this->mAge = person.mAge;
        
        return *this;
        
    }
    
#endif
    
    // 析构函数
    ~Person2()
    {
        cout << "Person2析构函数: " << __func__ << endl;
        
        if (this->pName != NULL) {
            
            delete [] this->pName;
        }
    }
    
private:
    char* pName;
    int mID;
    int mAge;
};

void test03()
{
    
    Person2 person1("tom", 110, 18);
    Person2 person2("John", 112, 19);
    
    cout << "person1: " << person1;
    cout << "person2: " << person2;
    
    person2 = person1;
    
    cout << "person2: " << person2;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test03();
    
    return 0;
}
