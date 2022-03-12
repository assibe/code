//
//  main.c
//  模拟实现memove
//
//  Created by zhourenxi on 2022/1/26.
//

void *my_memcpy ( void * destination, const void * source, int  num ){
    char *ret = destination;
    int a = 0;
    for (*(char*)destination++ = *(char*)source++; a < num; a++);
    return ret;
}



#include <stdio.h>
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
