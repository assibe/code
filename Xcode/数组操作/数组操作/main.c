//
//  main.c
//  数组操作
//
//  Created by zhourenxi on 2021/11/5.
//

#include <stdio.h>
void init(int p[],int b){
    int i = 0;
   for (i = 0; i<b-1; i++) {
        p[i] = 0;
    }
}

void print(int p[],int b){
    int i;
    for (i = 0; i < b -1; i++) {
        printf("%d  ",p[i]);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int p[10];
    int b = sizeof(p)/sizeof(p[0]);
    init(p,b);
    print(p,b);
    return 0;
}
