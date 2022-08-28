//
//  main.cpp
//  继承尝试
//
//  Created by zhourenxi on 2022/8/21.
//

//
//class test{
//
//public:
//    int c = 0;
//    int b = 0;
//};
//
//class test1{
//
//public:
//    test _test;
//};

//class test1:public test{
//
//public:
//    int m = 0;
//};
//
//class test2:public test{
//
//public:
//    int n = 0;
//};
//
//
//class test3: virtual  public test2,virtual public test1{
//
//public:
//    int m = 1;
//};

#include <iostream>
#include <stdio.h>
using namespace std;

class Base{
    
public:
    virtual void Fun1(){
        
        cout << "Fun1()"<< endl;
    }
    
private:
    int _b;
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Base b;
    
    b.Fun1();
    
    cout << "测试";
    return 0;
}
