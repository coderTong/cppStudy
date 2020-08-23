//
//  main.cpp
//  39友元01
//
//  Created by codew on 8/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Building;

// 友元类
class MyFriend {
    
public:
    // 友元成员函数
    void lookAtBedRoom(Building& building);
    void playInBedRoom(Building& building);
    
    int getBuildingCID(Building& building);
};




class Building {
    
    // 全局函数 做 友元 函数
    friend void cleanBedRoom(Building& building);
//#if 0
//    // 成员函数 做 友元 函数
////    friend void MyFriend::lookAtBedRoom(Building& building);
////    friend void MyFriend::playInBedRoom(Building& building);
////
////    friend int MyFriend::getBuildingCID(Building& building);
//#else
//    // 友元类
//    friend class MyFriend;
////    friend class NiBaBa;
//#endif
    
    friend class MyFriend;
    
public:
    
    Building();
    
public:
    string mSittingRoom;
    
private:
    string mBedRoom;
    int cId;
    
};


class NiBaBa{
    
public:
    // 不是朋友类 不能访问
//    int getBuildingCID(Building& building)
//    {
//        return building.cId;
//    }
};


void MyFriend::lookAtBedRoom(Building &building)
{
    cout << "我的朋友参观" << building.mBedRoom <<endl;
}

void MyFriend::playInBedRoom(Building &building)
{
    cout << "我的朋友 在 玩耍" << building.mBedRoom <<endl;
}

int MyFriend::getBuildingCID(Building &building)
{
    return building.cId;
}

// 友元全局函数
void cleanBedRoom(Building& building)
{
    cout << "友元 全局函数 访问" << building.mBedRoom << endl;
}

Building::Building()
{
    this->mSittingRoom = "客厅";
    this->mBedRoom = "卧室";
    
    this->cId = 101;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    Building building;
    MyFriend myFriend;
    
    cleanBedRoom(building);
    
    myFriend.lookAtBedRoom(building);
    myFriend.playInBedRoom(building);
    
    
    int cId = myFriend.getBuildingCID(building);
    
    cout << "看看 Building私有类:" << cId << endl;
    
    // 不能访问
//    int cID2 = building.cId;
//    cout << "看看 Building私有类:" << cID2 << endl;
    
    
    return 0;
}
