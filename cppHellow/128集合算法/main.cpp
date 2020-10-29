//
//  main.cpp
//  128集合算法
//
//  Created by codew on 10/25/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <vector>
#include <algorithm>
#include <functional>
//#include <numeric>//算术生成算法的头文件


using namespace std;

void showVector(vector<int>&ve)
{
    for (vector<int>::iterator it = ve.begin(); it != ve.end(); it++) {
        
        cout << *it << " " ;
    }
}

//set_intersection算法 求两个set集合的交集
//注意:两个集合必须是有序序列

void test01()
{
    vector<int> v1;
    
    for (int i = 0; i < 10; i++) {
        
        v1.push_back(i);
    }
    
    showVector(v1);
    cout << endl << "========" << endl;
    
    vector<int> v2;
    for (int i = 5; i < 25; i++) {
        
        v2.push_back(i);
    }
    
    showVector(v2);
    cout << endl << "========" << endl;
    
    vector<int> v3;
    v3.resize( v1.size(), v2.size() );
    
    showVector(v3);
    cout << endl << "v3========" << endl;
    
    
    cout << "size: " << v2.size() << endl;
    cout << "capacity: " << v2.capacity() << endl;
    cout << endl << "========" << endl;
    
    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    
    for_each(v3.begin(), v3.end(), [](int val){
        
        cout << val << " ";
    });
    
    cout << endl << "========" << endl;
}

//set_union算法 求两个set集合的并集
void test02()
{
    vector<int> v1;
    
    for (int i = 0; i < 10; i++) {
        
        v1.push_back(i);
    }
    
    showVector(v1);
    cout << endl << "========" << endl;
    
    vector<int> v2;
    for (int i = 5; i < 15; i++) {
        
        v2.push_back( i);
    }
    showVector(v2);
    cout << endl << "========" << endl;
    
    vector<int> v3;
    v3.resize( v1.size() + v2.size() );
    set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    
    for_each(v3.begin(), v3.end(), [](int val){
        
        cout << val << " ";
    });
    
    cout << endl << "========" << endl;
}

//set_difference算法 求两个set集合的差集
//假如A集合有1,2,3,4,5 B集合有2,3,4,5,6 A集合减B集合的结果就是1

void test03()
{
    vector<int> v1;
//    for (int i = 2;  i < 7; i++) {
//
//        v1.push_back(i);
//    }
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(5);
    
    showVector(v1);
    cout << endl << "========" << endl;
    
    vector<int> v2;
    
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(5);
//    for (int i = 3; i < 8; i++) {
//
//        v2.push_back(i);
//    }
    
    showVector(v2);
    cout << endl << "========" << endl;
    
    
    vector<int> v3;
    
    v3.resize(min(v1.size(), v2.size()));
    set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), v3.begin());
    for_each(v3.begin(), v3.end(), [](int val) {
        
        cout << val << " ";
    });
    
    cout << endl << "========" << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test03();
    
    return 0;
}
