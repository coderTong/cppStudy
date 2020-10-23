//
//  main.cpp
//  120案例
//
//  Created by codew on 10/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <vector>
#include <map>
#include <string>
#include <ctime>

using namespace std;

#define SALE_DEPATMENT 1 //销售部门
#define DEVELOP_DEPATMENT 2 //研发部门
#define FINACIAL_DEPATMENT 3 //财务部门

class Woker
{
public:
    string name; // 姓名
    int age; // 年龄
    int salary;
};

// 创建员工

void createWoker( vector<Woker> &vWoker )
{
    srand( (unsigned int)time(NULL) );
    
    string setName = "ABCDE";
    
    for (int i = 0; i < 5; i++) {
        
        Woker woker;
        woker.name = "员工";
        
        woker.name += setName[i];
        
        woker.age = rand() % 30 + 30;
        
        woker.salary = rand() % 20000 + 20000;
        
        vWoker.push_back( woker);
    }
    
}

//分组，把分好组的员工放入mWokers
void wokerByGroup( vector<Woker>&vWoker, multimap<int, Woker>&mWokers )
{
    // 遍历员工
    for (vector<Woker>::iterator it = vWoker.begin(); it != vWoker.end(); ++it) {
        
        // 生成部门编号
        int id = rand() % 3 + 1;
        
        // 员工保存 到 mWokers
        mWokers.insert( make_pair(id, *it) );
    }
}

void myGroup( multimap<int, Woker> &mWokers, int id)
{
    // 查询id
    multimap<int, Woker>::iterator it = mWokers.find(id);
    
    // 查询部门人数
    int mCount = mWokers.count(id);
    
    // 临时变量
    int index = 0;
    
    for (; it != mWokers.end() && index < mCount; ++it, ++index) {
        
        cout << "name: " << it->second.name << " Age:" << it->second.age << " salary:" << it->second.salary << endl;
    }
    
    
}

// 打印员工信息
void printWoker( multimap<int, Woker> &mWokers)
{
    cout << "财务部门员工信息如下:" << endl;
    myGroup(mWokers, FINACIAL_DEPATMENT);
    
    cout << "研发部门员工信息如下:" << endl;
    myGroup(mWokers, DEVELOP_DEPATMENT);
    
    cout << "销售部门员工信息如下:" << endl;
    myGroup(mWokers, SALE_DEPATMENT);
}

void test()
{
    // 保存 未分组 的 员工信息
    vector<Woker> vWoker;
    
    //保存分组后员工的信息
    multimap<int, Woker> mWokers;
    
    
    // 创建员工
    createWoker( vWoker );
    
    //分组，把分好组的员工放入mWokers
    wokerByGroup(vWoker, mWokers);
    
    // 打印员工信息
    printWoker(mWokers);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test();
    
    return 0;
}
