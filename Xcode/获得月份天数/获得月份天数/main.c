//
//  main.c
//  获得月份天数
//
//  Created by zhourenxi on 2021/12/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int year = 0, mothe = 0 ;
    scanf("%d %d",&year,&mothe); 
        if (mothe == 1 ||mothe == 3 ||mothe == 5 ||mothe == 7 || mothe == 8 || mothe == 10  || mothe == 10) {
            printf("31\n");
        }
        else if (mothe == 2){
            if ((0 == mothe % 4 && 0 != mothe %100)) {
                printf("29\n");
            }
            else
                printf("28\n");
        }
        else
            printf("30\n");
    int c = 0;
    int v = 12;
    v = c + v;
    printf(<#const char *restrict, ...#>)
    return 0;
}
