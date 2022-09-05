//
//  main.cpp
//  排序子问题
//
//  Created by zhourenxi on 2022/9/5.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    long qu = 0;
    cin >> qu;
    
    int a[qu];
    for (long i = 0; i < qu ; i++) {
        
        cin >> a[i];
    }
    
    if (qu == 0) {
        cout << "0";
        return 0;
    }
    
    long amount = 0;
    int begin = 0;
    int end = 1;
    
    while (end < qu) {
        
        if (a[begin] < a[end]) {
            
            while (a[begin++] < a[end++]);
            amount++;
            
        }
        else{
            
            while (a[end++] >= a[begin]);
            amount++;
        }
        
    }
    
    cout << amount;
    
    return 0;
}
