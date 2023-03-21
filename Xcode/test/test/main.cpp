//
//  main.cpp
//  test
//
//  Created by 周仁玺 on 2023/3/20.
//

#include <iostream>
#include <mutex>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    std::mutex _mutex;
    unique_lock<mutex> lock(_mutex);
    pthread_cond_t &ti;
    
    return 0;
}
