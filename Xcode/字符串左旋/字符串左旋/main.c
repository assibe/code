//
//  main.c
//  字符串左旋
//
//  Created by zhourenxi on 2022/1/19.
//

#include <stdio.h>

void test(int k,char *a){
    int n = 0;
    for (n = 0; n < k; n++) {
        char  c = *a;
        *a = *(a+1);
        *(a + 1) = *(a + 2);
        *(a + 2) = *(a + 3);
        *(a + 3) = c;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int k = 0;
    scanf("%d",&k);
    char a[] = {'A','B','C','D'};
    test(k,a);
    printf("%s\n",a);
    return 0;
}


