//
//  main.c
//  模拟实现strcpy
//
//  Created by zhourenxi on 2022/1/22.
//

#include <stdio.h>
#include <string.h>

char * my_strcpy ( char * destination, const char * source ){
    char *ret = destination;
    while ((*destination++ = *source++)) ;
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char m[] = "fa;faca";
    char n[] = "foainfi";
//    my_strcpy(m, n);
    strcpy(m,n);
    printf("%s",m);
    return 0;
}
