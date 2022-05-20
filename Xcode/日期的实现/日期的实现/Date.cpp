//
//  Date.cpp
//  日期的实现
//
//  Created by zhourenxi on 2022/5/19.
//

#include "Date.hpp"



bool Date :: operator < (const Date &d){
    
    if (_year < d._year|| _mothe < d._mothe||_day < d._day) {
        return true;
    }
    return false;
};

bool Date::operator>(const Date &d){
    
    if (_year > d._year|| _mothe > d._mothe||_day > d._day) {
        return true;
    }
    return false;
}

bool Date::operator==(const Date &d){
    
    return _year == d._year && _mothe == d._mothe && _day == d._day;
}

bool Date::operator!=(const Date &d){
    
    if (_year == d._year && _mothe == d._mothe && _day == d._day) {
        return false;
    }
    return true;
}


int Date::GetMonthDay(int year, int month)
{
    assert(year >= 0 && month > 0 && month < 13);

    const static int monthDayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month == 2 && isLeapYear(year))
    {
        return 29;
    }
    else
    {
        return monthDayArray[month];
    }
}



Date Date::operator+(int day){
    
    Date ret(*this);//赋值
    ret += day;
    
    while (ret._day > GetMonthDay(ret._year,ret._mothe))
        {
            ret._day -= GetMonthDay(ret._year, ret._mothe);
            ret._mothe++;
            if (ret._mothe == 13)
            {
                ++ret._year;
                ret._mothe = 1;
            }
        }
    return ret;
}


Date &Date::operator+=(int day){
    
    *this = *this + day;
    return *this;
}
