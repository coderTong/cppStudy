//
//  NameTest.hpp
//  cppHellow
//
//  Created by codew on 7/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

//#ifndef NameTest_hpp
//#define NameTest_hpp
//
//#include <stdio.h>
////
////#endif /* NameTest_hpp */
//
//
//#pragma mark - ccccc
//
//
////#pragma once
//
//
//#include <iostream>


#pragma once

#include<iostream>
using namespace std;


using namespace::std;

namespace myNameTest1
{
// extern加上这个的话就 仅仅声明
extern int valueHaHa;
void funcOne1();
}

namespace myNameTest2
{
void funcOne1();
}

using namespace::myNameTest1;
