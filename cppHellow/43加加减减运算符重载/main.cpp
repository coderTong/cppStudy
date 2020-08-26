//
//  main.cpp
//  43加加减减运算符重载
//
//  Created by codew on 8/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using namespace std;

class Complex {
    
    friend ostream& operator<<(ostream& os, Complex& complex){
        
        os << "A: " << complex.mA << " B:" << complex.mB <<endl;
        
        return os;
    }
    
public:
    
    Complex(){
        
        mA = 0;
        mB = 0;
    }
    
    // 重载前置++
    Complex& operator++(){
        
        cout << __func__ << " 重载前置++" <<endl;
        
        mA++;
        mB++;
        
        return *this;
    }
    
    
    // 重载后置++
    Complex operator++(int){
        
        cout << __func__ << " 重载后置++" <<endl;
        
        Complex temp;
        
        temp.mA = this->mA;
        temp.mB = this->mB;
        
        
        mA++;
        mB++;
        
        return temp;
    }
    
    
    // 前置--
    Complex& operator--(){
        
        cout << __func__ << " 前置--" <<endl;
        
        mA--;
        mB--;
        
        return *this;
    }
    
    // 后置--
    Complex operator--(int){
        
        cout << __func__ << " 后置--" <<endl;
        
        Complex temp;
        
        temp.mA = mA;
        temp.mB = mB;
        
        
        mA--;
        mB--;
        
        return temp;
    }
    
    
    void showComplex(){
        
        cout << "A:" << mA << " B:" << mB << endl;
    }
    
    
    
private:
    int mA;
    int mB;
    
};


void test()
{
    
    Complex complex;
    
    complex++;
    
    cout << complex;
    
    ++complex;
//
//    cout << complex;
//
//
//    Complex ret = complex++;
//
//    cout << ret;
//
//    cout << complex;
//
//    cout << "-------" << endl;
//
//
//    ret--;
//    --ret;
//
//    cout << "ret: " << ret;
//
//    complex--;
//    --complex;
//
//    cout << "complex: " << complex;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    test();
    return 0;
}
