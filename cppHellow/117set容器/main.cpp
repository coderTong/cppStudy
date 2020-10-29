//
//  main.cpp
//  117set容器
//
//  Created by codew on 10/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;


void test()
{
    set<int>::iterator it;
//    it++;
//    it--;
    
    
}


void printSet(set<int> &s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it) {
        
        cout << *it << " ";
    }
    
    cout << endl;
}

/*
构造函数
set<T> st;//set默认构造函数：
mulitset<T> mst; //multiset默认构造函数:
set(const set &st);//拷贝构造函数

赋值操作
set&operator=(const set &st);//重载等号操作符
swap(st);//交换两个集合容器
大小操作
size();//返回容器中元素的数目
empty();//判断容器是否为空

插入和删除操作
insert(elem);//在容器中插入元素。
clear();//清除所有元素
erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(elem);//删除容器中值为elem的元素。


*/


void test01()
{
    set<int> s;
    
    s.insert(4);
    s.insert(8);
    s.insert(2);
    s.insert(10);
    s.insert(7);
    
    
    // 自身规则进行排序, 从小到大
    printSet(s);
}


struct myfunc
{
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }
};


void printSet2(set<int, myfunc> &s)
{
    for (set<int, myfunc>::iterator it = s.begin(); it != s.end(); ++it) {
        
        cout << *it << " ";
    }
    
    cout << endl;
}

// 改变set 容器的规则, 变为降序 (从大到小)
void test02()
{
    
    set<int, myfunc> s;
    s.insert(4);
    s.insert(8);
    s.insert(2);
    s.insert(18);
    s.insert(28);
    
    printSet2(s);
}


//set容器不允许有两个相同的元素
void test03()
{
    set<int, myfunc> s;
    s.insert(4);
    s.insert(8);
    s.insert(2);
    s.insert(18);
    s.insert(28);
    
    
    printSet2(s);
    cout << "--------" << endl;
    
    //注意：set容器不允许有两个相同的元素，但是插入相同的元素，编译不会报错，运算也不报错
    //只是不把数据输入容器
    s.insert(8);
    printSet2(s);
    cout << "--------" << endl;
    
    pair<set<int, myfunc>::iterator, bool> ret = s.insert(11);
    
    if (ret.second) {
        
        cout << "插入成功" << endl;
    }else{
        
        cout << "插入失败" << endl;
    }
    
    printSet2(s);
    cout << "--------" << endl;
    
    s.erase(2);
    s.erase(s.begin());
    printSet2(s);
    cout << "--------" << endl;
}


void print(int v)
{
    cout << v << " ";
}

// 不能通过 算法 排序
void test04()
{
    multiset<int>s;
    s.insert(4);
    s.insert(8);
    s.insert(2);
    s.insert(2);
    s.insert(7);
    
    
    // 自身规则进行排序, 从大到小
    // 不能通过算法, 排序来 排序关联式 容器的元素
    // error
//    sort(s.begin(), s.end());
    
    for_each(s.begin(), s.end(), print);
    cout << endl;
}

/*
查找操作
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
1.    count(key);//查找键key的元素个数
2.    lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
3.    upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

*/

void test05()
{
    
    set<int>s;
    s.insert(1);
    s.insert(8);
    s.insert(6);
    s.insert(9);
    s.insert(7);
    
    
    set<int>::iterator it = s.find(8);
    
    if ( it==s.end() ) {
        
        cout << "查找失败" << endl;
    }else{
        
        cout << "查找成功: " << *it << endl;
    }
    
    // 查找大于2的最小的数
    
    it = s.upper_bound(2);
    if ( it == s.end() ) {
        
        cout << "查找失败" << endl;
    }else{
        
        cout << "查找成功: " << *it << endl;
    }
    
    //返回大于等于2的两个最小的数，如果有2那么就返回2和大于2的最小数
    //返回容器中key与keyElem相等的上下限的两个迭代器。
    pair<set<int>::iterator, set<int>::iterator> ret = s.equal_range(1);
    cout << "--------" << endl;
    cout << *(ret.first) << endl;
    cout << *(ret.second) << endl;
    cout << "--------" << endl;
    
    
    multiset<int>s1;
    s1.insert(4);
    s1.insert(4);
    s1.insert(24);
    s1.insert(11);
    s1.insert(7);
    
    // 有几个4? 答2个
    cout << s1.count(4) << endl;
}

// 存储对象时, 需要告诉set容器规则
class Maker
{
public:
    Maker(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    
public:
    string name;
    int age;
};


struct MakerFunc
{
    bool operator()(const Maker &m1, const Maker &m2)
    {
        return m1.age > m2.age;
    }
};

void test06()
{
    set<Maker, MakerFunc> s;
    
    s.insert( Maker("aaa", 19) );
    s.insert( Maker("bbb", 29) );
    s.insert( Maker("ccc", 22) );
    s.insert( Maker("ddd", 21) );
    s.insert( Maker("eee", 32) );
    
    
    for (set<Maker, MakerFunc>::iterator it = s.begin(); it != s.end(); ++it) {
        
        cout << "Name: " << it->name << " Age: "<< it->age << endl;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test06();
    
    return 0;
}
