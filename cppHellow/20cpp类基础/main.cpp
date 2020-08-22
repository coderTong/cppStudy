//
//  main.cpp
//  20cpp类基础
//
//  Created by codew on 8/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Person {
    
    
    
public:
    void Dese(){
        cout << "你瞅啥! 看我身高" <<this->mTall << endl;
    }
    Person(){
        
        pName = (char *)malloc( sizeof("John"));
        strcpy(pName, "John");
        mTall = 174;
    }
    ~Person(){
        
       cout << "c++的dealloc" << endl;
        
        if (pName != NULL) {
            
            free(pName);
            pName = NULL;
        }
    }
public:
    int mTall; // 多高可以 告诉外人
    char *pName;
    
protected:
    int mMoney; // 多少钱, 只能儿子子孙知道
    
private:
    int mAge; // 年龄不能让外人知道
};





int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    
    Person p;
//    p.mTall = 170;
//    p.Dese();
    
    Person person;

    cout << person.pName << person.mTall << endl;
    return 0;
}
