//
//  main.cpp
//  特殊类的设计
//
//  Created by 周仁玺 on 2022/11/24.
//

#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

//不可以被拷贝的类

class CopyBan{
    
private:
    CopyBan(const CopyBan&);
    CopyBan& operator=(const CopyBan&);
};//类的私有化不可以被拷贝


//类只能在堆上面创建对象

class Heaponly{
    
    static Heaponly* Createobject(){
        
        return new Heaponly;
    }
    Heaponly(const Heaponly&) = delete;
    
private:
    Heaponly(){}
    
};

//只能在栈上创建对象

class Stackonly {
    
    static Stackonly* Createobj(){
        
        return Stackonly;
    };
    
private:
    Stackonly()
    :_a(0){}

    int _a;
};


//不可以被继承的类

class A final{
    
};

//



