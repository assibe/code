//
//  game.h
//  三字棋
//
//  Created by zhourenxi on 2021/11/10.
//

#include <stdio.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 50 //设置雷的个数
#include <stdlib.h>
#include <time.h>
void Initboard(char board[ROWS][COLS],int row,int col,char set);

void SetmIne(char mine[ROWS][COLS],int row,int col);

void Displayboard(char board[ROWS][COLS],int row,int col);

void Setmine(char mine[ROWS][COLS],int row,int col);

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col);
