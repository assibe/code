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

Date Date::operator+(int day){
    
    Date ret(*this);//赋值
    ret += day;
    
    return ret;
}

