//
//  main.cpp
//  19externc
//
//  Created by codew on 8/21/20.
//  Copyright © 2020 codertom. All rights reserved.
//

#include <iostream>

using  namespace  std;

#if 0

 #ifdef __cplusplus

 extern "C" {

 #if 0

 void func1();

 int func2(int a, int b);

 #else

 #include"MyModule.h"

 #endif

 }

 #endif

#else

 extern "C" void func1();

 extern "C" int func2(int a, int b);

#endif

int main(){

 func1();

 cout << func2(10, 20) << endl;

 return EXIT_SUCCESS;

}
