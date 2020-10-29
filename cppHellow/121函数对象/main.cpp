//
//  main.cpp
//  121函数对象
//
//  Created by codew on 10/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <functional>
#include <algorithm>
#include <vector>

using namespace std;

void test()
{
    vector<int> v;
    
    v.push_back(8);
    v.push_back(1);
    v.push_back(6);
    v.push_back(3);
    v.push_back(7);
    
    sort(v.begin(), v.end(), greater<int>() );
    
    for_each(v.begin(), v.end(), [](int val){
        
        cout << val << " ";
        
    });
}

void func()
{
    
}

struct Myfunc
{
public:
    Myfunc()
    {
        n = 0;
    }
    
    void operator()()
    {
        cout << " hello" << endl;
    }
    
public:
    int n;
};

void test01()
{
    plus<int> myplus;
    cout << myplus(10, 20) << endl;
}


// 谓词===============>
// 大于5的?

void printVector( vector<int> &ve)
{
    for (vector<int>::iterator it = ve.begin(); it != ve.end(); it++) {
        
        cout << *it << " ";
    }
}

struct greaterThanFive
{
    bool operator()(int v)
    {
        return v > 5;
    }
};

// 一元谓词
void test02()
{
    vector<int> v;
    for (int  i = 0; i < 10; i++) {
        
        v.push_back(i);
    }
    
    printVector(v);
    cout << endl;
    
    vector<int>::iterator ret = find_if( v.begin(), v.end(), greaterThanFive());
    if ( ret == v.end() ) {
        
        cout << "没有找到";
    }else{
        
        cout << "找到:" << *ret << endl;
    }
}


// 二元谓词

struct MyCompare
{
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};

void test03()
{
    
    vector<int> v;
    
    srand( (unsigned int)time(NULL) );
    
    for (int i = 0; i < 10; i++) {
        
        v.push_back( rand()%100 );
    }
    
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        
        cout << *it << " ";
    }
    
    cout << endl;
    
    
    // 排序算法
    
    sort( v.begin(), v.end(), MyCompare());
    
    for ( vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        
        cout << *it << " ";
    }
    
    cout << endl;
}



// 内联函数对象 ======================

//1. 算数类函数对象
//```cpp
//
//template<classT>T plus<T>//加法仿函数
//template<class T> T minus<T>//减法仿函数
//template<class T> T multiplies<T>//乘法仿函数
//template<class T> T divides<T>//除法仿函数
//template<class T> T modulus<T>//取模仿函数
//template<class T> T negate<T>//取反仿函数
//
//```
//
//
//2. 关系运算类函数对象
//
//```cpp
//
//template<class T>bool equal_to<T>//等于
//template<class T>bool not_equal_to<T>//不等于
//template<class T>bool greater<T>//大于
//template<class T>bool greater_equal<T>//大于等于
//template<class T>bool less<T>//小于
//template<class T>bool less_equal<T>//小于等于
//
//```
//
//
//3. 逻辑运算类仿函数
//
//
//```cpp
//
//template<class T>bool logical_and<T>//逻辑与
//template<class T>bool logical_or<T>//逻辑或
//template<class T>bool logical_not<T>//逻辑非
//
//```


void test04()
{
    
    equal_to<int> myEqual;
    plus<int>myPlus;
    
    if ( myEqual(10, 20) ) {
        
        cout << "相等" << endl;
    }else{
        
        cout << "不相等!" << endl;
    }
    
    
    cout << "myPlus: " << myPlus(10, 20) << endl;
}


void test05()
{
    vector<int> v;
    
    srand( (unsigned int)time(NULL) );
    
    for (int i = 0; i < 10; i++) {
        
        v.push_back( rand()%100 );
    }
    
    cout << "===========" << endl;
    printVector(v);
    cout << endl;
    
    
    cout << "===========" << endl;
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        
        cout << *it << " ";
    }
    
    cout << endl;
    
    
    sort( v.begin(), v.end(),  greater<int>() );
    
    cout << "===========" << endl;
    printVector(v);
    cout << endl;
    
    cout << "===========" << endl;
    for ( vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        
        cout << *it << " ";
    }
    
    cout << endl;
}




int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test05();
    
    return 0;
}
