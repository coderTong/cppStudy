//
//  main.cpp
//  115电梯案例
//
//  Created by codew on 10/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>
#include<list>
#include<vector>
#include<queue>
#include<string>
#include<ctime>
using namespace std;

// 抽象人员
class Student
{
public:
    string name;
    
};

// 打印人员
void printVector(vector<Student> &vec)
{
    for (vector<Student>::iterator it = vec.begin(); it != vec.end(); ++it) {
        
        cout << (*it).name << endl;
    }
}

// 创建人员
void createStudent(queue<Student>&que, int num)
{
    cout << "-------" << endl;
    
    string setName = "ABCDEFGHIJKLMN";
    
    int sum = rand() % 10;
    for (int i = 0; i < sum; i++) {
        
        Student stu;
        
        char buf[64] = {0};
        
        sprintf(buf, "%d", num);
        string s(buf);
        
        cout << "cc: " << s << endl;
        
        stu.name = "第";
        stu.name += s;
        stu.name += "层";
        stu.name += setName[i];
        
        
        que.push( stu ); // 每层的人员放入队列容器
        
    }
    
    cout << "-------" << endl;
}

// myList是电梯, que队列容器, pushV是拷贝 进电梯的人员
// 进电梯
int pushList( list<Student> &myList, queue<Student> &que, vector<Student> &pushV)
{
    int tmppush = 0; // 临时变量, 记录出电梯人员数
    
    while ( !que.empty() ) {
        
        if ( myList.size() >= 15 ) { // 电梯满了
            
            break;
        }
        
        
        Student s = que.front();
        
        // 拷贝到vector
        pushV.push_back(s);
        
        // 进电梯
        myList.push_back(s);
        
        // 队列中 队头 元素 出容器
        que.pop();
        tmppush++;
    }
                
    return tmppush;
    
}


// mylist是电梯, popV记录出电梯人员, num 层数
int popList(list<Student> &mylist, vector<Student> &popV, int num)
{
    int tmppop = 0;
    
    if ( num == 17 ) {
        
        while ( !mylist.empty() ) {
            
            Student s = mylist.front();
            // 把出电梯的 人员拷贝 到 popV 中
            
            popV.push_back(s);
            
            mylist.pop_front(); // 移除电梯的人
            
            tmppop++;
        }
    }
    
    
    int n = rand() % 5; // 随机出电梯人数
    
    if ( n == 0) {
        
        return tmppop;
    }
    
    // 当电梯有人, 且人数大于 等于 随机 出电梯的人数 才 让人出电梯
    
    if ( mylist.size() > 0 && mylist.size() >= n) {
        
        for (int i = 0; i < n; i++) {
            
            Student s = mylist.front();
            
            // 把出电梯的人员拷贝到 popV中
            popV.push_back(s);
            mylist.pop_front(); // 移除电梯的人
            tmppop++;
        }
    }
    
    
    return tmppop;;
}


void test()
{
    
    srand( (unsigned int)time(NULL) );
    
    list<Student>myList; // 创建电梯
    
    int pushNum = 0; //记录进电梯的总人数
    int popNum = 0; //记录出电梯的总人数
    
    vector<Student> pushV;//记录进电梯的人员
    vector<Student> popV;//记录出电梯的人员
    
    // 电梯上升
    for (int i = 1; i < 18; i++) {
        
        // 创建人员
        queue<Student> que;
        
        // 创建人员函数
        createStudent(que, i);
        
        // 判断是否能进电梯
        if ( myList.size() <= 15) {
            
            // 17层不要进人, 到17层事件 结束
            if (i < 17) {
                
                // 进电梯
                pushNum += pushList(myList, que, pushV);
            }
        }
        
        // 判断出电梯的条件
        if (myList.size() > 0) { // 电梯要有人才能出
            
            if (i > 1) { // 1.层时, 电梯是空的
                
                // 出电梯
                popNum += popList(myList, popV, i);
            }
        }
    }
    
    
    // 打印进电梯的人员
    printVector( pushV );
    cout << "进电梯人数: " << pushNum << endl;
    
    // 打印出电梯的人员
    printVector( popV );
    cout << " 出电梯人数: " << popNum << endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test();
    
    
    return 0;
}
