//
//  main.c
//  交换数组
//
//  Created by zhourenxi on 2021/11/5.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {12,313,5,526,421};
    int b[] = {32,31,343,42,434};
    int c[5];
    int i = 0;
    for (i = 0; i<5; i++) {
        c[i] = a[i];
    }
    for (i = 0; i<5; i++) {
        a[i] = b[i];
    }
    for (i = 0; i<5; i++) {
        b[i] = c[i];
    }
    return 0;
}
