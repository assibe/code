//
//  main.cpp
//  c++的学习
//
//  Created by zhourenxi on 2022/5/12.
//

#include <iostream>

template <class T>

void Swap(T &right ,T &left){
    int tmp = right;
    right = left;
    left = tmp;
    
}

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
    int _day = 10;
};




using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here..
    return 0;
}
