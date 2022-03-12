//
//  main.c
//  计算那切数（不用递归）
//
//  Created by zhourenxi on 2021/11/4.
//

#include <stdio.h>

int count(int x){
    int i,m1 = 1,m2 = 1;
    if (x<2) {
        return 1;
    }
    int c = 0;
    for (i = 2; i<=x; i++) {
        c = m2;
        m2 = m1 +c;
        m1 = c;
    }
    return m2;
 
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int a , b;
    scanf("%d",&a);
    b = count(a);
    printf("%d",b);
    return 0;
}
