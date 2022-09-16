//
//  main.cpp
//  vector的增删查改的模拟实现
//
//  Created by zhourenxi on 2022/9/13.
//

#include <iostream>
#include "vector.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    vector::vector<int> v;
    v.reserve(3);
    v.insert(0, 2);
    v.pop_back(2);
    cout <<v.size();
    
    
    
    
    return 0;
}
