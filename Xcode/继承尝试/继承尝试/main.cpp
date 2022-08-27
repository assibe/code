//
//  main.cpp
//  继承尝试
//
//  Created by zhourenxi on 2022/8/21.
//

#include <iostream>

class test{
    
public:
    int c = 0;
    int b = 0;
};

class test1{
    
public:
    test _test;
};

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

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    test1 m;
    cout << m._test.b<< endl;
    cout << m.test1::c;
    return 0;
}
