//
//  NameTest.cpp
//  cppHellow
//
//  Created by codew on 7/24/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include "NameTest.h"




namespace myNameTest1
{
int nibabadadupi;
}

namespace myNameTest1
{

int valueHaHa;

}

void myNameTest1::funcOne1()
{
    myNameTest1::nibabadadupi = 90;
    cout << __func__ << nibabadadupi << endl;
}
