//
//  main.c
//  调整奇数偶数顺序
//
//  Created by zhourenxi on 2021/11/23.
//

#include <stdio.h>

void sort_arr(int *arr,int sz){
    int left = 0;
    int right = sz - 1;
    while (left < right) {
        while (0 != *(arr+left) % 2&&left < right) {
            left++;
        }
        while (1 != *(arr + right)%2 && right > left) {
            right--;
        }
        int temp = 0;
        temp = *(arr+left);
        *(arr + left) = *(arr + right);
        *(arr+right) = temp;
    }
}


 void Disply(int arr[], int sz){
   
     int i = 0;
  
     for (; i < sz ; i++) {
        printf("%d\n",*(arr + i));
        
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int arr[] = {124,322,3132,432,1322,3232,322,31422,3142};
    
    int sz = sizeof(arr)/sizeof(arr[0]);
    
    
    sort_arr(arr,sz);
    Disply(arr,sz);
  
    return 0;
}

