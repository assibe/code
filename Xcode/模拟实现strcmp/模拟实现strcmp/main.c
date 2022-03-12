//
//  main.c
//  模拟实现strcmp
//
//  Created by zhourenxi on 2022/1/22.
//

#include <stdio.h>

int mu_strcmp ( const char * str1, const char * str2 ){
    while (*str1++ == *str2 ) {
        if (*str2 == '\0') {
            return 0;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
