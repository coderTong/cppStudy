//
//  main.cpp
//  40友元电视遥控器
//
//  Created by codew on 8/23/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

// 遥控器

class Remote;

// 电视
class Television {
    
    friend class Remote;
    
public:
    // 开机/关机
    enum{
        On,
        Off
    };
    
    
    // 音量从0到100
    enum{
        minVol,
        maxVol = 100
    };
    
    // 频道从1到255
    enum{
        minChannel = 1,
        maxChannel = 255
    };
    
    Television(){
        
        mState = Off;
        mVolume = minVol;
        mChannel = minChannel;
    }
    
    // 开/关 电视机
    void OnOrOff()
    {
        
        this->mState = ( this->mState == On ? Off : On );
        string stateStr = this->mState == On ? "开" : "关";
        cout << __func__ << "此时电视机状态: " << stateStr << endl;
    }
    
    // 调高音量
    void volumeUp()
    {
        if (this->mVolume >= maxVol) {
            return;
        }
        
        this->mVolume++;
        cout << __func__ << "此时电视机音量: " << this->mVolume << endl;
    }
    // 调低音量
    void volumeDown()
    {
        if (this->mVolume <= minVol) {
            return;
        }
        
        this->mVolume--;
        cout << __func__ << "此时电视机音量: " << this->mVolume << endl;
    }
    // 更换电视频道
    void channelUp()
    {
        if (this->mChannel >= maxChannel) {
            return;
        }
        
        this->mChannel++;
        cout << __func__ << "此时电视机频道: " << this->mVolume << endl;
    }
    
    // 更换电视频道
    void channelDown()
    {
        if (this->mChannel <= minChannel) {
            return;
        }
        
        this->mChannel--;
        cout << __func__ << "此时电视机频道: " << this->mVolume << endl;
    }
    
    // 展示当前电视状态信息
    
    void showTeleState()
    {
        
        cout << __func__ << "-------------" << endl;
        
        
        cout << "开机状态:" << (mState == On ? "已开机" : "已关机") << endl;
        
        if (mState == On){
            cout << "当前音量:" << mVolume << endl;
            cout << "当前频道:" << mChannel << endl;
        }

        cout << "-------------" << endl;
    }
    
private:
    // 电视状态, 开机/关机
    int mState;
    // 电视音量
    int mVolume;
    // 电视频道
    int mChannel;
    
};


// 电视机 调台只能 一个一个 的调.  遥控可以指定频道
// 电视遥控器
class Remote {
    
    
public:
    Remote(Television* television){
        
        this->television = television;
    }
    
public:
    // 开/关 电视机
    void OnOrOff()
    {
        television->OnOrOff();
    }
    // 调高音量
    void volumeUp()
    {
        television->volumeUp();
    }
    // 调低音量
    void volumeDown()
    {
        television->volumeDown();
    }
    
    // 更换电视频道
    void channelUp()
    {
        television->channelUp();
    }
    // 更换电视频道
    void channelDown()
    {
        television->channelDown();
    }
    
    
    // 设置频道  遥控新增功能
    
    void setChannel(int channel){
        
        if ( channel < Television::minChannel ||
             channel > Television::maxChannel  ) {
            
            return;
        }
        
        // 这里就提现了 友元
        television->mChannel = channel;
    }
    
    // 显示 电视当前信息
    
    void showTVInfo()
    {
        television->showTeleState();
    }
    
private:
    Television* television;
};



// 直接操作电视
void  test01(){

    Television television;

    television.showTeleState();

    television.OnOrOff(); //开机

    television.volumeUp(); //增加音量+1

    television.volumeUp(); //增加音量+1

    television.volumeUp(); //增加音量+1

    television.volumeUp(); //增加音量+1

    television.channelUp(); //频道+1

    television.channelUp(); //频道+1

    television.showTeleState();
}


// 通过遥控器 操作电视

void test02()
{
    
    // 创建电视
    Television television;
    
    // 创建遥控
    Remote remote(&television);
    
    remote.OnOrOff();

    remote.channelUp();//频道+1

    remote.channelUp();//频道+1

    remote.channelUp();//频道+1

    remote.volumeUp();//音量+1

    remote.volumeUp();//音量+1

    remote.volumeUp();//音量+1

    remote.volumeUp();//音量+1

    remote.showTVInfo();
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    test02();
    return 0;
}
