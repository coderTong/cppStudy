//
//  main.cpp
//  87类模板的应用
//
//  Created by codew on 10/18/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

template<class T>
class MyArray
{
public:
    /**
     C++提供了关键字explicit，禁止通过构造函数进行的隐式转换。声明为explicit的构造函数不能在隐式转换中使用。
     */
    explicit MyArray(int capacity)
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        
        pAddress = new T[this->m_Capacity];
    }
    
    // 拷贝 构造
    MyArray(const MyArray & arr)
    {
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        this->pAddress = new T[this->m_Capacity];
        
        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    
    
    // 重载 [] 操作符 arr[0]
    T& operator [](int  index)
    {
        return this->pAddress[index];
    }
    
    // 尾插法
    void Push_back(const T & val)
    {
        if (this->m_Capacity == this->m_Size) {
            
            return;
        }
        
        this->pAddress[this->m_Size] = val;
        this->m_Size++;
    }
    
    void Pop_back()
    {
        if (this->m_Size == 0) {
            
            return;;
        }
        
        this->m_Size--;
    }
    
    int getSize()
    {
        return this->m_Size;
    }
    
    ~MyArray()
    {
        if ( this->pAddress != NULL) {
            
            delete [] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
    }
    
private:
    T * pAddress;
    int m_Capacity;
    int m_Size;
};

// 测试代码

class Person
{
public:
    Person(){}
    Person(string name, int age)
    {
        this->mName = name;
        this->mAge = age;
        
    }
    
public:
    string mName;
    int mAge;
};


void PrintMyArrayInt(MyArray<int> &arr)
{
    for (int i = 0; i < arr.getSize(); i++) {
        
        cout << arr[i] << " ";
    }
    
    cout << endl;
}

void PrintMyPerson(MyArray<Person> &personArr)
{
    for (int i = 0; i < personArr.getSize(); i++) {
        
        cout << "姓名: " << personArr[i].mName << " 年龄: " << personArr[i].mAge << endl;
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
//    MyArray<int> myArrayInt(10);
//    for (int i = 0; i < 9; i++) {
//
//        myArrayInt.Push_back(i);
//    }
//    myArrayInt.Push_back(100);
//    PrintMyArrayInt(myArrayInt);
    
    
    MyArray<Person> myArrayPerson(10);
    Person p1("德玛西亚", 30);
    Person p2("后裔", 3);
    Person p3("亚瑟", 13);
    Person p4("狂铁", 12);
    Person p5("孙悟空", 22);

    myArrayPerson.Push_back(p1);
    myArrayPerson.Push_back(p2);
    myArrayPerson.Push_back(p3);
    myArrayPerson.Push_back(p4);
    myArrayPerson.Push_back(p5);
    PrintMyPerson(myArrayPerson);
    
    return 0;
}
