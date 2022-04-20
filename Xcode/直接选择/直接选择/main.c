//
//  main.c
//  直接选择
//
//  Created by zhourenxi on 2022/4/20.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

void Swap(int a,int b ){
    int tmp = a;
    a = b;
    b = tmp;
}

void Select(int *a,int n){
    int right;
    int left;
    right = 0;
    left = n - 1;
    
    int max = right;
    int min = left;
    
    while (right < left) {
        
        for (int i = right; i < left ; i++) {
            
            if (a[i] > a[max]) {
                max = i;
            }
            
            if (a[i] < a[min]) {
                
                min = i;
            }
        }
        Swap(a[left], a[min]);
        
        if (left == max ) {
            max = min;
        }
        
        Swap(a[right], a[max]);
        
    }
}
