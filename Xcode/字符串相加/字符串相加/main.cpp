//
//  main.cpp
//  字符串相加(变化相关的东西，进行加减)
//
//  Created by zhourenxi on 2022/7/31.
//

#include <iostream>
#include <string>


using namespace std;

class Solution {
public:
    std::string addStrings(std::string num1, string num2) {
        
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int add = 0;
        
        string ans = "";
        
        while (i >= 0 || j >= 0 || add != 0) {
            
            int x =  i >= 0 ? num1[i] - '0': 0 ;
            int y = j >= 0 ? num2[j] - '0':0;
        
            int result = x + y + add;
            ans.push_back('0' + result % 10);
            add = result / 10;
            i--;
            j--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};




//            int result = x + y + add;
//            ans.push_back('0' + result % 10);
//            add = result / 10;
//            i -= 1;
//            j -= 1;
//        }
//        // 计算完以后的答案需要翻转过来
//        reverse(ans.begin(), ans.end());
//        return ans;
//    }
//};
