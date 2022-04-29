//
//  main.c
//  快速排序
//
//  Created by zhourenxi on 2022/4/20.
//

#include <stdio.h>
#include <stdlib.h>

void Swap(int a, int b){
    
    int tmp = a;
    a = b;
    b = tmp;
}

int  PartSort2(int *a,int left,int right){//填坑法
    
    int keyi = left;
    int pit = left;
    
    while (right > left) {
        
        while (right > left && a[right] >= keyi) {
            right--;
        }//右边
        Swap(a[pit], a[right]);
        pit = right;
        
        while (right > left && a[left] <= keyi ) {
            left++;
        }//左边
        
        Swap(a[pit], a[left]);
        pit = left;
        
    }
    a[left] = a[pit];
    
    return left;
}

void QuickPart2(int *a,int begin,int end){//基本上都是使用这个模版！
    
    if (begin >= end ) {
        return;
    }
    int keyi = PartSort2(a, begin, end);
    
    QuickPart2(a, 0, keyi - 1);
    QuickPart2(a, keyi + 1, end);
    
}



int GetMiderInderx(int *a,int left,int right){//找中间数值
    
    int mid = left + (right - left) / 2;
    
    if (a[left] < a[mid]) {
        
        if (a[mid] < a[right]) {
            return mid;
        }
        else
            if (a[left] < a[right]) {
                return right;
            }
        else
            return left;
    }
    else{
        
        if (a[left] < a[right]) {
            return left;
        }
        else{
            if (a[right] > a[mid]) {
                return right;
            }
            else
                return mid;
        }
    }
    
}

int PartSort1(int *a,int right,int left){
    
    int keyi = left;
    
    while (left < right) {
        
        while (a[left] >= a[keyi]/*排除相等不移动*/&&/*防止发生越边界的情况！*/left < right) {
            left--;
        }
        
        while (a[right] <= keyi ) {//同理！
            right++;
        }
        
        Swap(a[right], a[left]);
    }
    
    return left;
}

void QuickSort1(int *a,int begin,int end){//基础法
    
    if (begin >= end) {
        return;
    }
    int keyi = PartSort1(a, begin, end);
    
    QuickSort1(a, begin, keyi - 1);
    QuickSort1(a, keyi + 1, end);
}

int PartSort3(int *a,int left,int right){//前后指针法
    
    int prev,cur;
    int keyi = left;
    prev = cur = left + 1;
    
    while (cur <= right) {
        
        if (a[cur] < a[keyi] && a[++prev] != a[cur]) {
            Swap(a[prev], a[cur]);
            cur++;
        }
    }
    
    Swap(a[prev], a[left]);
    return prev;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    int a[] = {3,2,3,43,2,43,45};
    QuickSort1(a, 0,sizeof(a)/sizeof(int) - 1);
    printf("Hello, World!\n");
    return 0;
}

