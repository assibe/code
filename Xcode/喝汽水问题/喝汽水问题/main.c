//
//  main.c
//  喝汽水问题
//
//  Created by zhourenxi on 2021/11/19.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int a = 20;
    int bottle_count = 0;
    int count = 0;
    while (a) {
        a--;
        bottle_count++;
        if (2 == bottle_count) {
            bottle_count = 0;
            a++;
        }
        count++;
    }
    printf("%d\n",count);
    return 0;
}
