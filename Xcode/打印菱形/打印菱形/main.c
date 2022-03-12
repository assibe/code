//
//  main.c
//  打印菱形
//
//  Created by zhourenxi on 2021/11/17.
//

#include <stdio.h>
void DisPlay(int conut,char set){
    int i = 0;
    for (i = 0; i < conut; i++) {
        printf("%c",set);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int j = 0;
    int blank = 6 ;
    int true = 1;
    for (j = 0; j < 13; j++) {
        if (j < 7) {
            DisPlay(blank,' ');
            DisPlay(true, '*');
            DisPlay(blank, ' ');
            printf("\n");
            blank--;
            true += 2;
            if (6 == j) {
                true -=4;
                blank += 2;
            }
    }
        else {
            DisPlay(blank,' ');
            DisPlay(true, '*');
            DisPlay(blank, ' ');
            printf("\n");
            true -=2;
            blank ++;
        }
    }
    return 0;
}
