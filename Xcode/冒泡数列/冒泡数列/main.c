//
//  main.c
//  冒泡数列
//
//  Created by zhourenxi on 2021/11/5.
//

#include <stdio.h>

void sort(int p[],int b){
    int i = 0;
    int a = 0;
    int c = 1;
    for (c =0; c < b-1; c++) {
        
        for (i = 0; i < b-1-c; i++) {
            if (p[i] > p[i+1]) {
                a = p[i];
                p[i] = p[i+1];
                p[i+1] = a;
            }
        }
    }
    }
   

void print(int c[],int b){
    int i = 0;
    for (i = 0; i < b; i++) {
        printf("%d  ",c[i]);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {123,12,12342,4241,31231,3241,53415,314,-42,13,4214,-4125,-25,41313423,-5252,25-52,-525};
    int b = sizeof(arr)/sizeof(arr[0]);
    sort(arr,b);
    print(arr,b);
    return 0;
}
