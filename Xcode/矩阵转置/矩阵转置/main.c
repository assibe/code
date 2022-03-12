//
//  main.c
//  矩阵转置
//
//  Created by zhourenxi on 2021/11/30.
//

#include <stdio.h>

int main(void) {
    // insert code here...
    int carry = 0;
    int list = 0;
    scanf("%d %d",&carry,&list);
    int arr[carry][list] ;
    int i = 0;
    int j = 0;
    for (i = 0; i < carry; i++) {
        for (j = 0; j < list; j++) {
            scanf("%d",&arr[i][j]);
        }
    }
    for (i = 0; i < list; i++) {
        for (j = 0; j < carry; j++) {
            printf("%d ",arr[j][i]);
        }
        printf("\n");
    }
    return 0;
}
