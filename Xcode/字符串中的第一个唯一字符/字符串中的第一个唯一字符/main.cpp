//
//  main.cpp
//  字符串中的第一个唯一字符
//利用双指针进行相关的操作
//  Created by zhourenxi on 2022/8/1.
//

#include <iostream>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        
        if (s.empty()) {
            return -1;
        }
        
        //正反进行遍历
        
        for(int i=0; i<s.size(); ++i){
        
              unsigned long index = s.find(s[i]);
            unsigned long reverse_index = s.rfind(s[i]);
        
              if(index == reverse_index)
                return i;
        
            }
        
        return -1;
    }
};

