//
//  main.c
//  三字棋
//
//  Created by zhourenxi on 2021/11/10.
//


#include "game.h"

void game(void){
    char mine[ROWS][COLS] = {0};//布置好雷之后
    char show[ROWS][COLS] = {0};//排出雷的信息
    Initboard(mine, ROWS, COLS, '0');//初始化雷
    Initboard(show, ROWS, COLS, '#');
    Setmine(mine,ROW,COL);
    Displayboard(show, ROW, COL);
    FindMine(mine,show,ROW,COL);
}


void menu(void){
    printf("***********************************\n");
    printf("*********1,piay********************\n");
    printf("*********0,exit********************\n");
    printf("***********************************\n");
    printf("-》");
}
int main(int argc, const char * argv[]) {
    // insert code here...
    srand((unsigned int)time(NULL));
    int input =0;
    do {
        menu();
        scanf("%d",&input);
        switch (input) {
            case 1:
                game();
                break;
            case 0:
                printf("退出游戏\n");
                break;
            default:
                printf("输入错误，请重新输入\n");
                break;
        }
    } while (input);
    return 0;
}
