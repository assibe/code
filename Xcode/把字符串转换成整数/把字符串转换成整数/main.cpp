//
//  main.cpp
//  把字符串转换成整数
//
//  Created by zhourenxi on 2022/7/13.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        
        if (str.size() == 0) {
            return 0;
        }
        
        const char *cstr = str.c_str();
        if (cstr == NULL) {
            return 0;
        }
        
        int n = 0;
        while (n <= str.size()) {
            
            if (<#condition#>) {
                <#statements#>
            }
        }
        
       
        return 0;
    }
};
