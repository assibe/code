//
//  main.c
//  strlen
//
//  Created by zhourenxi on 2021/11/23.
//

#include <stdio.h>
int my_strlen(*str){
    int c = 0;
    while (*str++ != '\0') {
        c++;
    }
    return c;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char b[] = {'d','d','a','f','w','f','s','w'};
    int n = 0;
    n = my_strlen(b);
    printf("%d",n);
    return 0;
}
