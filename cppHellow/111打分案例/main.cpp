//
//  main.cpp
//  111打分案例
//
//  Created by codew on 10/22/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

#include <vector>
#include <deque>
#include <string>
#include <algorithm> // 算法头文件
#include <ctime>

using namespace std;

// 目的: 5个学生, 10个评委, 10个评委的分数去掉 最高和最低分, 取平均分就是分数的分数
// 抽象学生
class Student
{
public:
    string name;
    int mScore;
};

void printDeque(deque<int>que)
{
    for (deque<int>::const_iterator it = que.begin(); it != que.end(); it++) {
        
        cout << *it << " ";
    }
    
    cout << endl;
}

// 1. 创建学生
void createStudent(vector<Student>& vstu)
{
    string setName = "ABCDE";
    
    for (int i = 0; i < setName.size(); i++) {
        
        // 创建学生
        Student stu;
        stu.name = "学生";
        stu.name += setName[i];
        stu.mScore = 0;
        vstu.push_back(stu); // 把学生 放入容器
        
    }
    
}

// 2. 评委给 学生 打分
void setScore( vector<Student>& vstu)
{
    // 这玩意让随机数, 更真实些, 让数据不同
    srand( (unsigned int)time(NULL) );
    
    // 遍历学生
    for ( vector<Student>::iterator it = vstu.begin(); it != vstu.end(); it++) {
        
        // 保存分数
        deque<int> dScore;
        // 评委给学生打分
        for ( int i = 0; i < 10; i++) {
            
            int score = rand() % 70 + 30;
            dScore.push_back(score);
        }
        
        // 排序
        sort(dScore.begin(), dScore.end());
        
        printDeque(dScore);
        cout << "========" << endl;
        
        // 去掉最高分
        dScore.pop_back();
        dScore.pop_front();
        
        // 求总分
        int tota = 0;
        for (deque<int>::iterator sit = dScore.begin(); sit != dScore.end(); ++sit) {
            
            tota += (*sit);
        }
        
        // 求平均分
        int agescore = tota / dScore.size();
        
        // 平均分 存储到 对象中
        it->mScore = agescore;
    }
    

}


bool myComapre(Student &s1, Student &s2)
{
    // 小到大
    // return s1.mScore < s2.mScore;
    
    // 大到小
    return s1.mScore > s2.mScore;
}

// 3. 排名并打印
void showStudentScore( vector<Student>& vstu )
{
    sort(vstu.begin(), vstu.end(), myComapre);
    
    for (vector<Student>::iterator it = vstu.begin(); it != vstu.end(); ++it) {
        
        cout << "Name:" << it->name << " Score:" << it->mScore << endl;
    }
}

void test()
{
    // 存储学生的容器
    vector<Student> vstu;
    
    // 1. 创建学生
    createStudent(vstu);
    
    // 2. 评委给学生打分
    setScore(vstu);
    
    // 3. 排名并打印
    showStudentScore(vstu);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test();
    
    return 0;
}
