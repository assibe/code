//
//  main.c
//  猜凶手
//
//  Created by zhourenxi on 2021/12/9.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int killer = 'a';
    for (killer = 'a'; killer <= 'd'; killer++) {
        if ((killer != 'a') + (killer == 'c') + (killer == 'd')  + (killer != 'd') == 3) {
            printf("%c\n",killer);
        }
    }
    return 0;
}
