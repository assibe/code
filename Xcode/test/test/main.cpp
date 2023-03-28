//
//  main.cpp
//  test
//
//  Created by 周仁玺 on 2023/3/20.
//

#include <iostream>
#include <mutex>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


using namespace std;

int main(int argc, const char * argv[],char *env[]) {
    // insert code here...
    
    int i = 1;
    float* p = (float*) &i;
    cout << *p << endl;
    
    return 0;
}
