//
//  main.cpp
//  红黑树模拟实现
//
//  Created by 周仁玺 on 2022/10/2.
//

#include <iostream>
#include "RBTree.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    int a[] = {2,32,5,647,514,1213,12524,52,31};
    
    RBTree<int, int> t;
    for(auto e:a){
        
        t.insert(make_pair(e, e));
    }
    
    cout << _Heiht(t);
    return 0;
}
