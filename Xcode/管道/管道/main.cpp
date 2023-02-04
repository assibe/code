//
//  main.cpp
//  管道
//
//  Created by 周仁玺 on 2023/2/4.
//

#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    int pipefd[2] = {0};
    if (pipe(pipefd) != 0) {
        cout << "创建成功" << endl;
        
    }
    
    int fd = fork();
    
    if (fd == 0) { //子程序
        
        close(pipefd[0]);
        char i[64] = "i am fathe";
        
        while (1) {
            sleep(10);
            write(pipefd[1], i, strlen(i));
        }
          }
    
    close(pipefd[1]);
    while (1) {
        char buff[64] ;
        char m = read(pipefd[0], buff, sizeof(buff));
        
        if (m == 0) {
            break;
        }
        else{
            
            printf("%s\n",buff);
        }
    }
    
    return 0;
}
