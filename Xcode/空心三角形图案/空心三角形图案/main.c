//
//  main.c
//  空心三角形图案
//
//  Created by zhourenxi on 2021/11/30.
//

#include <stdio.h>

int main(void) {
    // insert code here...
    int n = 0;
    while (~scanf("%d",&n) != EOF) {
        char arr[20][20] = {'\0'};
        int i = 0;
        for (i = 0; i < n; i++) {
            int j = 0;
            for (j = 0; j < n; j++) {
                arr[i][j] = ' ';
            }
        }
        //全部为空格
        
        for (i = 0; i < n; i++) {
            arr[i][0] = '*';
        }
        //第一行的全部*号
        
        int j = 0;
        for (j = 0; j < n; j ++) {
            arr[j][j] = '*';
        }//补齐右边的*号
        
        for (i = 0; i < n; i++) {
            arr[n - 1][i] = '*';
        }
        for (i = 0; i < n; i ++) {
            int j = 0;
            for (j = 0; j < n; j ++) {
                printf("%c",arr[i][j]);
            }
            printf("\n");
        }
    }
       
    return 0;
}
