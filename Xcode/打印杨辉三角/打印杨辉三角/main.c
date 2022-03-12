//
//  main.c
//  打印杨辉三角
//
//  Created by zhourenxi on 2021/11/29.
//
#define NMBER 5
#include <stdio.h>

int main(void){
    int arr[1000][1000] = {0};
    
    int i = 0;
    for (i = 0; i < NMBER; i++) {
        arr[i][0] = 1;
    }
    int j = 0 ;
    for ( j = 1 ; j < NMBER; j++) {
        arr[j][j] = 1;
    }
    //初始化两边的数值
    
    int c = 0;
    for (c = 2; c < NMBER; c++) {
        int b = 0;
        for (b = 1; b < NMBER; b++) {
            arr[c][b] = arr[c-1][b - 1] + arr[c - 1][b];
        }
    }
    //中间数组
    
    int m = 0;
    int e = 0;
    for (m = 0; m < NMBER; m++) {
        for (e = 0; e <= m; e++) {
            printf("%d",arr[m][e]);
        }
        printf("\n");
    }
    
    return 0;
}
