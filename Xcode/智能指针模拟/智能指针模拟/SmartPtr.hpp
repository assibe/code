//
//  SmartPtr.hpp
//  智能指针模拟
//
//  Created by 周仁玺 on 2022/10/28.
//

#ifndef SmartPtr_hpp
#define SmartPtr_hpp

#include <stdio.h>

#endif /* SmartPtr_hpp */

namespace zhorenxi {

template<class T>
class SmartPtr{
    
public:
    SmartPtr(T* ptr)
    :_ptr(ptr)
    {};
    
    ~SmartPtr(){
        
        delete _ptr;
        _ptr = nullptr;
        
    };
    
private:
    T* _ptr;
};

template<class T>

class auto_ptr{
    
  
    
private:
    T* _ptr;
};





};
