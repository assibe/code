//
//  Date.hpp
//  日期的实现
//
//  Created by zhourenxi on 2022/5/19.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>

#endif /* Date_hpp */

class Date{
public:
    
    int GetMotheDay;//某一个年份的天数。
    
    Date (int year = 1,int mothe = 1, int dayy = 1);//默认进行初始化
    
    Date(const Date&d);//进行拷贝构造（与引用差不多）。
    
    Date operator+(int day)const;
    
private:
    int _year;
    int _mothe;
    int _day;
};
