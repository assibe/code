//
//  main.cpp
//  string类的模拟实现
//
//  Created by zhourenxi on 2022/8/1.
//

#include <iostream>
#include "string.hpp"

using namespace std;
using namespace zhorenxi;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    zhorenxi::string s1(";foafa");
    zhorenxi::string s2(s1);
    cout << s1.c_str() << endl;
    
    return 0;
}



