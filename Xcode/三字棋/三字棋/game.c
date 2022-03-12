//
//  game.c
//  三字棋
//
//  Created by zhourenxi on 2021/11/10.
//

#include "game.h"
void Initboard(char board[ROWS][COLS],int row,int col,char set){
    int i = 0;
    int j = 0;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            board[i][j] = set ;
        }
    }
}

void Displayboard(char board[ROWS][COLS],int row,int col){
    int i = 0;
    int j = 0;
    for (i = 0; i <=col; i++) {
        printf("%d",i);
    }
    printf("\n");
    for (i = 1; i  <= row; i++) {
        printf("%d",i);
        
        for (j = 1; j <= col; j++) {
            
            printf("%c",board[i][j]);
        }
        printf("\n");
    }
}

void Setmine(char mine[ROWS][COLS],int row,int col){
    int count = EASY_COUNT;
    while (count) {
        int x = rand()%row +1;
        int y = rand()%col +1;
        if (mine[x][y] == '0') {
            mine[x][y] =  '1';
            count--;
        }
    }
}
int get_mine_count(char mine[ROWS][COLS],int x,int y){
    return mine[x - 1][y] +
    mine[x - 1][y - 1] +
    mine[x][y - 1] +
    mine[x + 1][y - 1] +
    mine[x + 1][y] +
    mine[x + 1][y + 1] +
    mine[x][y + 1] +
    mine[x - 1][y + 1] - 8*'0';
}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col){//mine是雷的布局。show是主页面
    int x = 0;
    int y = 0;
    int win = 0;
    while (win < row*col-EASY_COUNT) {
        printf("请输入要排查的坐>>");
        scanf("%d %d",&x,&y);
        if (x  > 0 && x <= row &&y > 0 && y <= col) {
            if (mine[x][y] == '1') {
                printf("恭喜你被炸死\n");
                Displayboard(mine, row, col);
                break;
            }
            else
            {
                int n = get_mine_count(mine,x,y);
                show[x][y] = n+'0';
                Displayboard(show, row, col);
                win++;
            }
                
        }
        else{
            printf("坐标错误，请重新输入\n");
        }
          if (EASY_COUNT == win) {
            printf("恭喜你，排雷成功");
            Displayboard(mine, ROW, COL);
        }
    }
}


