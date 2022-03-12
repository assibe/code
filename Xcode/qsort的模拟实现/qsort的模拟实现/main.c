//
//  main.c
//  qsort的模拟实现
//
//  Created by zhourenxi on 2022/2/17.
//

void myqsort(void * base, int nitems, int size, int(*compar)(const void *, const void *))
{
    int i, j;
    char * st = (char *)base;
    char tmp[16];
 
    for (i = 0; i < nitems - 1; i++)
    {
        for (j = 0; j < nitems - 1 - i; j++)
        {
            if (compar(st + j * size, st + (j + 1) * size))
            {
                memcpy(tmp, st + j * size, size); 
                memcpy(st + j * size, st + (j + 1) * size, size);
                memcpy(st + (j + 1) * size, tmp, size);
            }
        }
    }
}
