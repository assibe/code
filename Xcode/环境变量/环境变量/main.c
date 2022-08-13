//
//  main.c
//  环境变量
//
//  Created by zhourenxi on 2022/8/13.
//

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, const char * argv[]) {
    // insert code here...
            
        pid_t id = fork();
        printf("ID:%d\n",id);
   
    return 0;
}
