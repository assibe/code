//
//  main.c
//  判断是不是字母
//
//  Created by zhourenxi on 2021/11/15.
//

#include<stdio.h>
#include<ctype.h>
int main(){
    char ch = 0;
    while(scanf("%c",&ch) != EOF){
        getchar();
        if(isalpha(ch)){
            printf("%c is an alphabet.\n",ch);
        }
        else
            printf("%c  is not an alphabet.\n",ch);
    }
    return 0;
}
