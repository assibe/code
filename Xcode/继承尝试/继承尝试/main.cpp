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

//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//class Base{
//
//public:
//    virtual void Fun1(){
//
//        cout << "Base::Fun1()"<< endl;
//    }
//
//private:
//    int _b = 4;
//
//};
//
//class Base1:public Base{
//
//    virtual void Fun1(){
//
//        cout << "Base1::Fun1()"<<endl;
//    }
//};
//
//
//
//int main(int argc, const char * argv[]) {
//    // insert code here...
//
//    Base b;
//
//    b.Fun1();
//
//    cout << "测试";
//    return 0;
//}

//
//#include <iostream>
//
//using namespace std;
//class A
//{
//public:
//  virtual void f()
//  {
//    cout<<"A::f()"<<endl;
//  }
//};
//
//class B : public A
//{
//public:
//   virtual void f()
//  {
//    cout<<"B::f()"<<endl;
//  }
//};
//
//int main(){
//
//    A* pa = (A*)new B;
//    pa->f();
//    return  0;
//}
//

#include <iostream>
using namespace std;

class A
{
public:
  A ():m_iVal(0){test();}
  virtual void func() { std::cout<<m_iVal<<" ";}
  void test(){func();}
public:
  int m_iVal;
};

class B : public A
{
public:
  B(){test();}
  virtual void func()
  {
    ++m_iVal;
    std::cout<<m_iVal<<" ";
  }
};

int main(){
    
  A*p = new B;
  p->test();
  return 0;

}
