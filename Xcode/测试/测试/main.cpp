//
//  main.cpp
//  测试
//
//  Created by 周仁玺 on 2023/2/26.
//


#include <unistd.h>
#include <iostream>

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
  
  
    alarm(1);
    int cent =  0;
    while(1){
        cent++;
        std::cout<< cent << std::endl;
    }
    return 0;
}
