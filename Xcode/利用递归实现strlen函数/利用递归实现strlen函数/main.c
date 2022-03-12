//
//  main.c
//  利用递归实现strlen函数
//
//  Created by zhourenxi on 2021/11/3.
//

#include <stdio.h>

int str(char *x){
    if (*x !=  '\0') {
        return 1+ str(x+1);
    }
    else{
        return 0;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    char a[] = "fsfaufaff";
    int b = 0;
    b = str(a);
    printf("%d",b);
    
    return 0;
}
