//
//  main.cpp
//  日期的实现
//
//  Created by zhourenxi on 2022/5/17.
//

#include <iostream>


class Date
{
public:
// 获取某年某月的天数
int GetMonthDay(int year, int month);
  // 全缺省的构造函数
Date(int year = 1900, int month = 1, int day = 1);

  // 拷贝构造函数
// d2(d1)
Date(const Date& d);
   
  // 赋值运算符重载
// d2 = d3 -> d2.operator=(&d2, d3)
Date& operator=(const Date& d);

  // 析构函数
~Date();

  // 日期+=天数
Date& operator+=(int day);

  // 日期+天数
Date operator+(int day);

  // 日期-天数
Date operator-(int day);

   // 日期-=天数
Date& operator-=(int day);

  // 前置++
Date& operator++();

  // 后置++
Date operator++(int);

  // 后置--
Date operator--(int);

  // 前置--
Date& operator--();
  // >运算符重载
bool operator>(const Date& d);

  // ==运算符重载
bool operator==(const Date& d);

  // >=运算符重载
inline bool operator >= (const Date& d);
   
  // <运算符重载
bool operator < (const Date& d);

   // <=运算符重载
bool operator <= (const Date& d);

  // !=运算符重载
bool operator != (const Date& d);

  // 日期-日期 返回天数
int operator-(const Date& d);
private:
int _year;
int _month;
int _day;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
