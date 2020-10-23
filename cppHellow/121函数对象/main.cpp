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

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test01();
    
    return 0;
}
