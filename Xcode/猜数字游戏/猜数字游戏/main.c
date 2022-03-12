//
//  main.c
//  猜数字游戏
//
//  Created by zhourenxi on 2021/10/29.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int num;
    srand((unsigned int)time(NULL));
    do {
        printf("************************************\n");
        printf("********** 输入1进行游戏***************\n");
        printf("********** 输入0推出游戏***************\n");
        scanf("%d",&num);
        if (1==num) {
            
            int guess = 0;
            int r = rand()%100+1;
            while (1)
            {
                
                printf("猜数字:>");
                scanf("%d", &guess);
                if (guess < r)
                {
                    printf("猜小了\n");
                }
                else if (guess > r)
                {
                    printf("猜大了\n");
                }
                else
                {
                    printf("恭喜你，猜对了\n");
                    break;
                }
            }
        }
        else if(0==num)
            break;
        else
            printf("请重新输入");
    } while (num==1);
    return 0;
}
