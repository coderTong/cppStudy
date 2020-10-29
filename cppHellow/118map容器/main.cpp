//
//  main.cpp
//  118map容器
//
//  Created by codew on 10/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>
#include <map>
#include <string>

using namespace std;


void test()
{
    map<int, string>::iterator it;
//    it--;
}

/*
插入数据元素操作
map.insert(...); //往容器插入元素，返回pair<iterator,bool>
map<int, string> mapStu;
// 第一种 通过pair的方式插入对象
mapStu.insert(pair<int, string>(3, "小张"));
// 第二种 通过pair的方式插入对象
mapStu.inset(make_pair(-1, "校长"));
// 第三种 通过value_type的方式插入对象
mapStu.insert(map<int, string>::value_type(1, "小李"));
// 第四种 通过数组的方式插入值
mapStu[3] = "小刘";
mapStu[5] = "小王";

*/

template<class T>
void printMap(T &m)
{
    for (map<int, string>::iterator it = m.begin(); it != m.end(); ++it) {
        
        cout << "key: " << it->first << " value: " << it->second << endl;
    }
}


void test01()
{
    
    map<int, string> mymap;
    
    
    mymap.insert( pair<int, string>(3, "aaa") );
    mymap.insert( make_pair(6, "bbb") );
    mymap.insert( map<int, string>::value_type(2, "ccc") );
    mymap[4] = "ddd";
    
    printMap(mymap);
}

// 改变规则
struct mapFunc
{
    bool operator()(int key1, int key2)
    {
        return  key1 > key2;
    }
};


/**
 map<int, string, mapFunc> myMap; macOS 编译不过, 不可以改变规则
 2020年10月27日00:05:12
 */
void test02()
{
    map<int, string> myMap;
    
    myMap.insert( pair<int, string>(3, "aaa") );
//
    myMap.insert( make_pair(6, "bbb") );
    myMap.insert( map<int, string>::value_type(2, "ccc") );
    myMap[4] = "ddd";
//
    printMap(myMap);
}

//注意：[]方式插入数据,如果没有实值，那么键值也是存在的
void test03()
{
    
    map<int, string> mymap;
    mymap.insert( pair<int, string>(3, "aaa") );
    mymap.insert( make_pair(6, "bbb") );
    mymap.insert( map<int, string>::value_type(2, "ccc") );
    mymap[4] = "ddd";
    
    printMap(mymap);
    
    cout << "size: " << mymap.size() << endl;
    cout << mymap[100] << endl; // 虽然没得100, 但是这样一搞以后, 就会多一个值
    
    cout << "size: " << mymap.size() << endl;
}
/*
查找
find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。

*/
void test04()
{
    map<int, string> myMap;
    
    myMap[1] = "aaa";
    myMap[2] = "bbb";
    myMap[3] = "ccc";
    myMap[4] = "ddd";
    myMap[5] = "eee";
    
    
    map<int, string>::iterator it = myMap.find(3);
    
    if ( it == myMap.end() ) {
        
        cout << "查找失败" << endl;
    } else {
        // first如果是key就好看些,  second如果是value就好些
        cout << "key: " << it->first << " value: " << it->second << endl;
    }
    
    // 查找大于等于5的最小数
    it = myMap.lower_bound(5);
    if ( it == myMap.end() ) {
        
        cout << "查找失败" << endl;
    } else {
        
        cout << "key: " << it->first << " value: " << it->second << endl;
    }
    
    cout << "--------------------" << endl;
    
    // 返回 大于 等于 2的两个最小的数, 如果有2那么就 返回2和大于 2的最小数
    pair<map<int, string>::iterator , map<int, string>::iterator > ret = myMap.equal_range(2);
    
    if ( ret.first != myMap.end() ) {
        
        cout << " key: " << ret.first->first << " value: " << ret.first->second << endl;
    }
    
    
    if ( ret.second != myMap.end() ) {
        
        cout << " key: " << ret.second->first << " value: " << ret.second->second << endl;
    }
    
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test04();
    return 0;
}
