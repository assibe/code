//
//  main.c
//  计算求和
//
//  Created by zhourenxi on 2021/11/17.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a = 0;
    scanf("%d",&a);
    int Sn = 0;
    int i = 0;
    int fingure = 0;
    int c = 1;
    for (i = 0; i <= 5; i++) {
        
        if (i != 0) {
            c *= 10;
        }
        fingure += a*c;
        Sn +=fingure;
    }
    printf("%d",Sn);
    return 0;
}
