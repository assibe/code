//
//  main.c
//  strcpy
//
//  Created by zhourenxi on 2021/11/23.
//

#include <stdio.h>

#include<assert.h>
char * my_strcpy ( char * destination, const char * source ){
    while((*destination++ = *source++)) {
    };
    return destination;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char ch1[] = "fsfafsafdsfsa";
    char ch2[14] ;
    my_strcpy(ch2, ch1);
    char *p = ch2;
    while (*p != '\0') {
        printf("%c",*p);
       *(p++);
    }
    return 0;
}
