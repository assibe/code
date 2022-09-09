//
//  main.cpp
//  进程尝试
//
//  Created by zhourenxi on 2022/8/29.
//

#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[])
{
   fork();
    (fork() && fork()) || fork();
   fork();
    
    set<int> s1;
    
    printf("dfaf");
    
    
    return 0;
}
