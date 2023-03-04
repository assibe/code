//
//  main.cpp
//  线程实验
//
//  Created by 周仁玺 on 2023/3/3.
//

#include <iostream>
#include <unistd.h>
#include <pthread.h>

using namespace std;

void *rout(void){
    
    cout << "f'iafa" << endl;
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    pthread_t tis;
    pthread_create(tis, nullptr, rout(), nullptr);
    
    return 0;
}
