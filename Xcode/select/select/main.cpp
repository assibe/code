//
//  main.cpp
//  select
//
//  Created by 周仁玺 on 2023/3/4.
//

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int fd[2] = {0};
    fd_set readset;
    struct timeval i = {300,0};
//    i.tv_usec;
    std::cout << sizeof(fd_set) << std::endl;
    
//    select(fd[2], <#fd_set *#>, <#fd_set *#>, <#fd_set *#>, <#struct timeval *#>)
    
    return 0;
}
