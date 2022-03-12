//
//  main.c
//  利用普通strlen的模拟
//
//  Created by zhourenxi on 2021/11/3.
//

 #include <stdio.h>
int srt(char *x){
    int n;
    for (n = 0; *x !='\0'; x++) {
        n++;
    }
    return n;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    char a[] = "fsfhka";
    int b;
    b = srt(a);
    printf("%d",b);
    return 0;
}
