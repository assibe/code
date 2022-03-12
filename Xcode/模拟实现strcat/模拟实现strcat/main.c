//
//  main.c
//  模拟实现strcat
//
//  Created by zhourenxi on 2022/1/22.
//

#include <stdio.h>
#include <assert.h>

char * my_strcat ( char * destination, const char * source ){
    assert(destination&&source);
    char *ret = destination;
    while (*destination){
        destination++;
    }
    while ((*destination++ = *source++));
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
