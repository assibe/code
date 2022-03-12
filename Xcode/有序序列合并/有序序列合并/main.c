//
//  main.c
//  有序序列合并
//
//  Created by zhourenxi on 2022/2/15.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 0;
    int m = 0;
    int arr1[2000];
    int arr2[1000];
    scanf("%d\n%d\n",&n,&m);
    
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr1[n]);
    };
    
    for (int n = 0; n < m;n++) {
        scanf("%d",&arr2[n]);
    };
    //读入数据
    int j = 0,i = 0;
    
    while (i < n && j < m)
        {
            if (arr1[i] < arr2[j])
            {
                // arr3[k++] = arr1[i];
                printf("%d ", arr1[i]);
                i++;
            }
            else
            {
                //arr3[k++] = arr2[j];
                printf("%d ", arr2[j]);
                j++;
            }
        }
        if (j == m)
        {
            for (; i < n; i++)
            {
                // arr3[k++] = arr1[i];
                printf("%d ", arr1[i]);
            }
        }
        else
        {
            for (; j < m; j++)
            {
                //  arr3[k++] = arr2[j];
                printf("%d ", arr2[j]);
            }
        }
    return 0;}

