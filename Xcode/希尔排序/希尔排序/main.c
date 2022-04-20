//
//  main.c
//  希尔排序
//
//  Created by zhourenxi on 2022/4/18.
//

#include <stdio.h>
#include <stdlib.h>

void ShellSort(int *a,int n){//插入排序
    
//    int gap = 3;
//    for (int b = 0; b <gap; b++) {//多层循环进行，进行！
//
//        int i = b;
//        for (; i < n -gap/*限制的倒数第二个东西！一定小于这个东西*/; i += gap) {//一组排序
//
//            int end = i;
//            int tmp = a[end +gap];
//
//            while (end >= 0) {
//
//                if (tmp < a[end]) {
//
//                    a[end + gap] = a[end];
//                    end -= gap;
//
//                }
//                else
//                    break;
//            }
//            a[end + gap] = tmp;
//        }
//    }
    
    
    //通过两层进行控制
    int gap = n;
    while (gap > 1) {
        
        gap = gap/3 + 1 ;
        
        for (int i = 0; i < n -gap/*限制的倒数第二个东西！一定小于这个东西*/; i += gap) {//一组排序
    //对于组的插入（相隔距离gap个进行简单的顺序的更换，根据大小。去除外面一层循环）
                int end = i;
                int tmp = a[end +gap];
    
                while (end >= 0) {
    
                    if (tmp < a[end]) {
    
                        a[end + gap] = a[end];
                        end -= gap;
    
                    }
                    else
                        break;
                }
                a[end + gap] = tmp;
            }
    }
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int a[] = {123,4342,43,54,32,21};
    ShellSort(a, sizeof(a)/sizeof(int));
    
    printf("Hello, World!\n");
    return 0;
}

//希尔排序

