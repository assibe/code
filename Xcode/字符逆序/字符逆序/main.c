//
//  main.c
//  字符逆序
//
//  Created by zhourenxi on 2021/11/17.
//

#include<stdio.h>
int main(){
    char ch[10000] = {0};
    gets(ch);
    int j = 0;
    for (j = 0; ch[j] != '\0'; j++);
    int m = 0;
    while (m < j-1) {
        char a = ch[m];
        ch[m] = ch[j-1];
        ch[j-1] = a;
        m++;
        j--;
    }
    int i = 0;
    for (i = 0; ch[i]; i++) {
        printf("%c",ch[i]);
    }
    return 0;
}
