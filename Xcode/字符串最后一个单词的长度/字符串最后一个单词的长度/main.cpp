//
//  main.cpp
//  字符串最后一个单词的长度
//
//  Created by zhourenxi on 2022/7/31.
//

#include <iostream>
#include <string>
using namespace std;


int Word_Length(string &str){
    
    if (str.empty()) {
        return 0;
    }
    
    int index = str.rfind(' ');
    if(index == string::npos){
        
        return str.size();
        
    }
    
       return str.size()-index-1;
}

int main(void){
    
    string s;
    getline(cin,s);
    int index = Word_Length(s);
    cout << index;
    return 0;
}


//#include<iostream>
//#include<string>
//using namespace std;
//
//int Calc_Word_Length(string &str)
//{
//  if(str.empty())
//    return 0;
//  int index = str.rfind(' ');
//  if(index == string::npos)
//    return str.size();
//  return str.size()-index-1;
//}
//
//int main()
//{
//  string str;
//  getline(cin, str);
//  int len = Calc_Word_Length(str);
//  cout<<len;
//  return 0;
//}
