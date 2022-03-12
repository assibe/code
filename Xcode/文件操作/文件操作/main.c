//
//  main.c
//  文件操作
//
//  Created by zhourenxi on 2022/2/24.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    FILE * pf = fopen("text.txt", "w");
    fputc(stdout, "fafa");
    return 0;
}
