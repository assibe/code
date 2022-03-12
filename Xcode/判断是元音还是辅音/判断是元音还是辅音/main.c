//
//  main.c
//  判断是元音还是辅音
//
//  Created by zhourenxi on 2021/11/14.
//

#include<stdio.h>
int main(){
    char ch;
    while(scanf("%c",&ch) != EOF){
        getchar();
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            printf("Vowel\n");
        else
            printf("Consonant\n");
        }
        
    return 0;
}
