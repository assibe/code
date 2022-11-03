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
    
public:
    auto_ptr(T* ptr)
    :_ptr(ptr){};
    
    ~auto_ptr(){
        
        if (_ptr) {
            delete _ptr;
            _ptr = nullptr;
        }
    }
    
    auto_ptr(auto_ptr<T>& sp)
    :_ptr(sp)
    {
        sp._ptr = nullptr;
    }

    
    T& operator*(){

        return *_ptr;
    }

    T* operator->(){

        return _ptr;
    };
    
    T *get(){
        
        return _ptr;
    }
    
private:
    T* _ptr;
};
};

template<class T>

class unique_ptr{
    
    
    unique_ptr(T* ptr)
    :_ptr(ptr)
    {}
    
    ~unique_ptr(){
        
        if (_ptr) {
            delete _ptr;
            _ptr = nullptr;
        }
    }

    T& operator*(){

        return *_ptr;
    }

    T* operator->(){

        return _ptr;
    };
    
    T *get(){
        
        return _ptr;
    }
    
    
//    unique_ptr<T>& opertor=(const unique_ptr<T>& sp) = delete;
    unique_ptr(const unique_ptr<T>& sp) =delete;
    unique_ptr<T>& operator=(const unique_ptr<T> &sp) = delete;
    
private:
    T* _ptr;
    
};


template <class T>

class shared_ptr{
    
    void Release(){
        
        if (--(*_pCount) == 0 && _ptr) {
            delete _ptr;
            _ptr = nullptr;
            delete _pCount;
            _pCount = nullptr;
        }
    }
    
    ~shared_ptr(){
        
        Release();
    }
    
    shared_ptr(T* ptr)
    :_ptr(ptr)
    ,_pCount(new int(1))
    {}
    
    shared_ptr(const shared_ptr<T>& sp)
    :_ptr(sp)
    ,_pCount(sp._pCount){
        
        (*_pCount)++;
    }
    
    T& operator*(){

        return *_ptr;
    }

    T* operator->(){

        return _ptr;
    };
    
    T *get(){
        
        return _ptr;
    }
    
    
    
private:
    T* _ptr;
    int* _pCount;
    
};

template<class T>

class weak_ptr{
    
private:
    T* _ptr;
};
