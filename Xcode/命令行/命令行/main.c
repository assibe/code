//
//  main.c
//  命令行
//
//  Created by zhourenxi on 2022/8/20.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
        
    for (int i = 0; i < argc; i++) {
        
        printf("%s",argv[i]);
    }
    
    return 0;
}
