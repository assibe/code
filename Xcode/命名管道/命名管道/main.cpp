//
//  main.cpp
//  命名管道
//
//  Created by 周仁玺 on 2023/2/4.
//

#include <iostream>
#include <sys/errno.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    
    mkfifo("/zhorenxi", EACCES);
    
    perror("dadfaf");
    return 0;
}
