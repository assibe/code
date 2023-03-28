//
//  main.cpp
//  剑指 Offer 58 - II. 左旋转字符串
//
//  Created by 周仁玺 on 2023/3/28.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string reverseLeftWords(string s, int n) {
        return (s+s).substr(n,s.size());//substr为截取函数，直接把两个相同的字符串把前面截取了，只剩下后面的安装正常进行排列就可以操作了！
    }
};
