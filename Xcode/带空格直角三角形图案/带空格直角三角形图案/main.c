//
//  main.c
//  带空格直角三角形图案
//
//  Created by zhourenxi on 2021/12/9.
//

#include<stdio.h>
int main(void){
    int n,i,j;
    while(scanf("%d",&n)!=EOF){
        getchar();
        for(i=1;i<=n;i++){
            
            for(j=1;j<=n;j++){
                if(j<(n+1-i))
                    printf("  ");
                if(j>=(n+1-i))
                    printf("* ");
            }
            
            printf("\n");
        }
    }
    return 0;
}

