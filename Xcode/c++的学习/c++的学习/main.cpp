//
//  main.cpp
//  c++的学习
//
//  Created by zhourenxi on 2022/5/12.
//

#include <iostream>

class Date{
public:
    Date(int year = 1,int mothe = 1,int day = 1){
        _day = day;
        _mothe = mothe;
        _year = year;
    }
    
private:
    int _mothe;
    int _year;
    int _day;
};

struct Date1{
    int _mothe;
    int _year;
    int _day;
public:
    Date1(int year = 1,int mothe = 1,int day = 1){
        _day = day;
        _mothe = mothe;
        _year = year;
    }
};

using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    Date1 i;
    
    printf("%d\n",i._year);
    return 0;
}
