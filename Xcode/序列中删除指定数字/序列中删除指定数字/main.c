//
//  main.c
//  序列中删除指定数字
//
//  Created by zhourenxi on 2021/11/30.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int n = 0;
    scanf("%d",&n);
    int arr[n];
    int i = 0;
    for (i = 0; i < n; i++) {
        scanf("%d ",&arr[i]);
    }
    int det = 0;
    scanf("%d",&det);
    for ( i = 0; i < n; i++) {
        if (det != arr[i]) {
            printf("%d ",arr[i]);
        }
    }
    return 0;
}
