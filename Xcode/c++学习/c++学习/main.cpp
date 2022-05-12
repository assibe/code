//
//  main.cpp
//  c++学习
//
//  Created by zhourenxi on 2022/5/11.
//

#include <iostream>
int Add(int a,int b){
    return a + b;
}
double  Add(double a,double b){
    return a + b;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int c = Add(10,20);
    std::cout << c << std::endl;
    c = Add(10.2,20.4);
    std::cout << c << std::endl;
    return 0;
}
