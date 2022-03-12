//
//  main.c
//  交换奇偶位
//
//  Created by zhourenxi on 2022/2/24.
//

#include <stdio.h>

#define SwapIntBit(n) (((n) & 0x55555555) << 1 | ((n) & 0xaaaaaaaa) >> 1)

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
