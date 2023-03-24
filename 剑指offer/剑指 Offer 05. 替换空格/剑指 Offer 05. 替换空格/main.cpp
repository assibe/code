//
//  main.cpp
//  剑指 Offer 05. 替换空格
//
//  Created by 周仁玺 on 2023/3/24.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        
        int count = 0,len = (int)s.size();
        for(char c : s){
            if (' ' == c) {
                count++;
            }
        }
        s.resize(len + 2 * count);
        
        int i = len -1,j = (int)s.size() - 1;
        for(;i < j;i--,j--){
            
            if (s[i] != ' ') {
                s[j] = s[i];
            }
            else{
                s[j -2 ] = '%';
                s[j - 1] = '2';
                s[j] = '2';
                j -= 2;
            }
            
        }
        
        return s;
        
    };
};
