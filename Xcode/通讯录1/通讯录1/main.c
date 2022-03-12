//
//  main.c
//  通讯录1
//
//  Created by zhourenxi on 2022/2/14.
//
#include "contact.h"
#include <stdio.h>
#include<stdio.h>
#include <string.h>
#include <assert.h>

enum Oprion
{
    EXIT,//0
    ADD,
    DEL,
    SEARCH,
    MODIFY,
    SORT,
    SHOW
};

void menu(void){
    printf("***************************\n");
    printf("*** 1,add   2,del *********\n");
    printf("*** 3,search 4,modify******\n");
    printf("******** 5.sort  6.show****\n");
    printf("********0.exit        *****\n");
    printf("***************************\n");
    printf("***************************\n");
}//主菜单

   
int main(int argc, const char * argv[]) {
    // insert code here...
    int input = 0;
    Contact con;
    InitContact(&con);
    
    do
    {
        menu();
        printf("请选选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case ADD:
            AddContact(&con);
            break;
        case DEL:
            DeleteContact(&con);
            break;
        case SEARCH:
            break;
        case MODIFY:
            break;
        case SORT:
            break;
        case SHOW:
            ShowContact(&con);
            break;
        case EXIT:
            printf("退出通讯录\n");
            break;
        default:
            printf("选择错误\n");
            break;
        }
    }while(input);

}
