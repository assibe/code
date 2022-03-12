//
//  main.c
//  无
//
//  Created by zhourenxi on 2021/10/31.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...//简单的关机游戏
    system("shutdown -t -s 60");
    char p;
    printf("请输入：我是猪!要不然关机");
    puts(&p);
    if (0==strcmp(&p,"我是猪")) {
        system("shutdown -a");
    }
    return 0;
}
