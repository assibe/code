//
//  main.c
//  字符串旋转结果
//
//  Created by zhourenxi on 2022/1/19.
//

#include <string.h>

int result(char *s,char *m){
    int n = sizeof(s);
    int c = 0;
    for (c = 0; c < n; m++) {
        
        int c = *s;
        int q = 0;
        for (q = 0; q < n; q++) {
            *(s + q ) = *(s +q +1);
        }
        *(s + n - 1) = c;//交换一次的结果
      
        if (strcmp(s,m) == 0 ) {
            return 1;
        }
    }
    return 0;
}
