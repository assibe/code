//
//  main.cpp
//  反转字符串中的单词 III
//
//  Created by zhourenxi on 2022/8/1.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    
    void Reverse(string &s, int start, int end){
        
        char tmp;
        while (start < end) {
            
             tmp = s[start];
            s[start] = s[end];
            s[end] = tmp;
            
            start++;
            end--;
        }
        
    }
    
    string reverseWords(string s){
        
        size_t end = 0;
        size_t start = 0;
        
        while (start < s.size()){
            
            end = s.find(' ',start);
            if (end == string::npos) {//开始到末位位置信息进行判断
                
                end = s.size();
                break;
                
            }
            
            //找到空格，之后首先进行交换位置
            Reverse(s,start,end - 1);
            start = end + 1;
            
        }
        
        Reverse(s, start, end - 1);
        return s;
        
    }
};









class Solution {
public:
  void Reverse(string &s, int start, int end)
  {
    char tmp;
    while(start < end)
    {
      tmp = s[start];
      s[start] = s[end];
      s[end] = tmp;

      start++;
      end--;
    }
  }

  string reverseWords(string s)
  {
    size_t start = 0;
    size_t end = 0;
    while(start < s.size())
    {
      end = s.find(' ', start);
      if(end == string::npos){

        end = s.size();
        break;
      }

      Reverse(s, start, end-1);
      start = end+1;
    }
    Reverse(s, start, end-1);
    return s;
  }
};
