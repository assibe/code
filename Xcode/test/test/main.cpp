//
//  main.cpp
//  test
//
//  Created by 周仁玺 on 2023/3/20.
//

#include <iostream>
#include <mutex>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::mutex _mutex;
    unique_lock<mutex> lock(_mutex);
    pthread_cond_t &ti;
    
    va_list a;
    struct sockaddr local;
    return 0;
}
