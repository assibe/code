//
//  main.cpp
//  c++的学习
//
//  Created by zhourenxi on 2022/5/12.
//

#include <iostream>
#include <string>
#include <stdio.h>
#include <string>


class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        //s[start,end) 前面包含 后面不包含
        int start(0), end(0), length(0), result(0);
        int sSize = int(s.size());
        while (end < sSize)
        {
            char tmpChar = s[end];
            for (int index = start; index < end; index++)
            {
                if (tmpChar == s[index])
                {
                    start = index + 1;
                    length = end - start;
                    break;
                }
            }

            end++;
            length++;
            result = std::max(result, length);
        }
        return result;
    }
};
