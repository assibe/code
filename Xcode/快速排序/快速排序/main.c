//
//  main.c
//  快速排序
//
//  Created by zhourenxi on 2022/4/30.
//


#include <stdio.h>
#include <stdlib.h>

void Swap(int *a,int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int  PartSort1(int *a,int left,int right){
    
    int keyi = left;
    
    while (left < right) {
        
        while (a[right] >= a[keyi] && left < right) {
            right--;
        }
        
        while (a[left] <= a[keyi] && left < right) {
            left++;
        }
        Swap(&a[right],& a[left]);
    }
    
    Swap(&a[right], &a[keyi]);
    return left;
}
void QuickSort1(int *a,int begin,int end){//Hora排序
    
    if (begin >= end) {
        return;
    }
   int keyi =  PartSort1(a, begin, end);
    
    QuickSort1(a,begin,keyi - 1);
    QuickSort1(a, keyi + 1, end);
}

int  PartSort2(int *a,int left,int right){
    int keyi = a[left];
    int pit = left;
    
    while (left < right) {
        
        while (a[right] >= keyi && left < right) {
            right--;
        }
        a[pit] = a[right];
        pit = right;
        
        while (a[left] <= keyi && left < right) {
            left++;
        }
        a[pit] = a[left];
        pit = left;
        
    }
    a[pit] = keyi;
    return pit;
}

void QuickSort2(int *a,int begin,int end){
    if (begin >= end) {
        return;
    }
    int keyi = PartSort2(a,begin, end);
    QuickSort2(a, begin, keyi - 1);
    QuickSort2(a, keyi + 1, end);
}

int PartSort3(int *a,int left,int right){
    int keyi = left;
    int prev = left;
    int cur = left +1;
    
    while (cur <= right) {
        
        if (a[cur] <  a[keyi] && a[++prev] != a[cur]) {
            Swap(&a[cur], &a[prev]);
        }
        cur++;
    }
    
    Swap(&a[prev], &a[keyi]);
    return prev;
}
void QuickSort3(int *a,int begin,int end){
    if (begin >= end) {
        return;
    }
    int keyi = PartSort3(a,begin, end);
    QuickSort3(a, begin, keyi - 1);
    QuickSort3(a, keyi + 1, end);
}






int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {12,32,34,4,23,43,6,4234124,6,423,54,34,32,5};
    QuickSort3(a, 0, sizeof(a)/sizeof(int) - 1);
    
    for (int i = 0; i < sizeof(a)/ sizeof(int); i++) {
        printf("%d ",a[i]);
    }
    return 0;
}

