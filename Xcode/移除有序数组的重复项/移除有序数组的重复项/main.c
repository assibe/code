//
//  main.c
//  删除有序数组中的重复项
//
//  Created by zhourenxi on 2022/3/12.
//

#include <stdio.h>
#include <assert.h>

int removeDuplicates(int* nums, int numsSize){
    assert(nums);
    int left = 0;
    int dest = 0;
    int right = 1;
    
    for (right = 1; right < numsSize; right++) {
        
        if (nums[right] != nums[left]) {
            
            nums[dest++] = nums [left];
            left = right;
        }
        
    }
    
    nums[dest++] = nums[left];
    
    return dest ;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    
    int nums[] = {1,1,2}; // 输入数组
    int numSize = sizeof(nums) / sizeof(int);
    printf("%d",numSize);
    
    int expectedNums = 2; // 长度正确的期望答案
    
    if (expectedNums == removeDuplicates(nums,numSize)) {
        printf("成功");
    }
    return 0;
}

