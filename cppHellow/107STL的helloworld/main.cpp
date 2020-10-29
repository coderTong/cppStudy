//
//  main.cpp
//  107STL的helloworld
//
//  Created by codew on 10/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <vector> // 容器
#include <algorithm> // 算法头文件
#include <string>

using namespace std;


// 加入算法的回调函数
void MyPrint(int val)
{
    cout << val << " ";
}

// 1. 存储基础数据类型

void test01()
{
    // 容器
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    // 获取开始 位置 的迭代器
    vector<int>::iterator begin = v.begin();
    // 获取结束位置的迭代器
    vector<int>::iterator end = v.end();
    
    // 遍历算法
    for_each(begin, end, MyPrint);
    cout << endl;
}

// 2.容器存储对象
class Maker
{
public:
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    
    ~Maker()
    {
        cout << "析构函数进来: name: " << this->name << " age:" << this->age << endl;
    }
    
public:
    string name;
    int age;
};

ostream &operator << (ostream &out, Maker &m)
{
    out << "Name: " << m.name << " Age:" << m.age << endl;
    return out;
}

void test02()
{
    vector<Maker> v;
    v.push_back(Maker("狂铁", 20));
    v.push_back(Maker("亚瑟", 26));
    v.push_back(Maker("后羿", 46));
    v.push_back(Maker("孙悟空", 126));
    v.push_back(Maker("典韦", 26));
    
    // 获取开始 和 结束位置的迭代器
    vector<Maker>::iterator begin = v.begin();
    vector<Maker>::iterator end = v.end();
    
    while ( begin != end ) {
        
        cout << (*begin);
        begin++;
    }
}

// 3. 存储对象的指针
/**
 这个好像要节约内存些,
 上面的好像创建了好多对象, 但是上面的不用自己管理内存
 */
void test03()
{
    vector<Maker *> v;
    
    // 创建数据
    Maker *m1 = new Maker("狂铁", 20);
    Maker *m2 = new Maker("亚瑟", 26);
    Maker *m3 = new Maker("后羿", 46);
    Maker *m4 = new Maker("孙悟空", 126);
    Maker *m5 = new Maker("典韦", 26);
    
    v.push_back(m1);
    v.push_back(m2);
    v.push_back(m3);
    v.push_back(m4);
    v.push_back(m5);
    
    
    vector<Maker*>::iterator begin = v.begin();
    vector<Maker*>::iterator end = v.end();
    
    while ( begin != end ) {
        
        cout << (*begin)->name << "  " << (*begin)->age << endl;
        ++begin;
    }
    
    delete m1;
    delete m2;
    delete m3;
    delete m4;
    delete m5;
    
}

// 4. 容器嵌套容器
void test04()
{
    vector<vector<int>> vs;
    
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    vector<int> v5;
    
    for (int i = 0;  i < 5; i++) {
        
        v1.push_back( i + 10);
        v2.push_back( i + 10);
        v3.push_back( i + 10);
        v4.push_back( i + 10);
        v5.push_back( i + 10);
    }
    
    vs.push_back(v1);
    vs.push_back(v2);
    vs.push_back(v3);
    vs.push_back(v4);
    vs.push_back(v5);
    
    vector<vector<int>>::iterator begin = vs.begin();
    vector<vector<int>>::iterator end = vs.end();
    
    while ( begin != end ) {
        
        vector<int>::iterator sbegin = (*begin).begin();
        vector<int>::iterator send = (*begin).end();
        
        while ( sbegin != send) {
            
            cout << *sbegin << " ";
            ++sbegin;
        }
        
        cout << endl;
        ++begin;
         
    }
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
   
    test02();
    
    return 0;
}
