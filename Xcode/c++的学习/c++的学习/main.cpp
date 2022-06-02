//
//  main.cpp
//  c++的学习
//
//  Created by zhourenxi on 2022/5/12.
//

#include <iostream>
#include <string>
#include <stdio.h>

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
    class m1{
        int c;
        
    };
private:
    int _mothe;
    int _year;
    int _day = 10;
};

template <class T>
int N1(T a) {
    return a;
}


using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here..
    cout << N1(32);
    
    return 0;
}
