//
//  main.c
//  环境变量
//
//  Created by zhourenxi on 2022/8/13.
//

#include <stdio.h>
#include <unistd.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    while (1) {
        
        printf("PID:%d,PPID:%d\n",getpid(),getppid());
        sleep(1);
    }
    
    return 0;
}
