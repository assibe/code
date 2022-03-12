//
//  main.c
//  杨氏矩阵
//
//  Created by zhourenxi on 2022/2/17.
//

#include <stdio.h>
 
int findnum(int a[][3], int x, int y, int f)
{
    int i = 0, j = x - 1;
 
    while (j >= 0 && i < y)
    {
        if (a[i][j] < f)
        {
            i++;
        }
        else if (a[i][j] > f)
        {
            j--;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}
 
int main()
{
    int a[][3] = { {1, 3, 5},
                  {3, 5, 7},
                  {5, 7, 9} }; 
 
    if (findnum(a, 3, 3, 2))
    {
        printf("It has been found!\n");
    }
    else
    {
        printf("It hasn't been found!\n");
    }
 
    return 0;
}
