//
//  vector.hpp
//  vector的增删查改的模拟实现
//
//  Created by zhourenxi on 2022/9/13.
//

#ifndef vector_hpp
#define vector_hpp

#include <assert.h>
#include <stdio.h>

#endif /* vector_hpp */

namespace vector {

template<class T>
class vector{
    
public:
    
    typedef T* iterator;
    typedef const T* const_iterator;
    
    //重写定义
    vector()
    :_start(nullptr)
    , _finish(nullptr)
    , _endofstoage(nullptr)
    {}
    
    template<class InputItertor>
    vector(InputItertor fist,InputItertor last)
    :_start(nullptr)
    ,_finish(nullptr)
    ,_endofstoage(nullptr){
        
        while (fist != last) {
            
            push_back(*fist);
            
        }
        
    }
    
    vector(size_t n,const T& val = T())
    :_start(nullptr)
    ,_finish(nullptr)
    ,_endofstoage(nullptr){
        
        reserve(n);
        for (size_t i = 0; i < n; i++) {
            
            push_back(val);
            
        }
        
    }
    
    vector(int n,const T& val = T())
    :_start(nullptr)
    ,_finish(nullptr)
    ,_endofstoage(nullptr)
    {
        reserve(n);
        for (int i = 0; i < n; i++) {
            push_back(val);
        }
        
    };
    
    void swap(vector<T>& v){
        
        swap(_start,v._start);
        swap(_finish,v._endofstoage);
        swap(_endofstoage,v._endofstoage);
    }
    
    vector(const vector<T>& v)
    :_start(nullptr)
    ,_finish(nullptr)
    ,_endofstoage(nullptr)
    {
        vector<T> tmp(v.begin,v.end);//赋值给tmp，然后进行更换
        swap(tmp);
    }
    
    vector<T>& operator=(vector<T> v){
        
        swap(v);
        return *this;
    }
    
    
    ~vector(){
        
        if (_start) {
            _start = _endofstoage = _finish = nullptr;
        }
        
    }
    
    iterator begin(){
        
        return _start;
    }
    
    
    iterator end(){
        return _finish;
    }
    
    iterator begin() const{
        
        return _start;
        
    }
    
    iterator end() const{
        
        return _finish;
        
    }
    
    size_t size()const{
        
        return _endofstoage - _start;//从末尾减去头
        
    }
    
    size_t capacity() const{
        
        return _endofstoage - _start;
        
    }
    
    void reserve(size_t n){//容量控制
        
        size_t sz = size();
        if (n > capacity()) {
            
            T* tmp = new T[n];
            if (_start) {
                
                for (size_t i = 0; i < n; i++) {
                    
                    tmp[i] = _start[i];
                    
                }
                
                delete [] _start;
                
            }
            _start = tmp;
        }
        _finish =  _start + sz;
        _endofstoage = _start + n;
    }
    
    void push_back(const T &x){
        
        insert(x);
        
    }
    
    void pop_back(){
        
        erase(end() - 1);
    }
    
    T& operator[](size_t pos){
        
        assert(pos < size());
        
        return _start[pos];
    }
    
    const T& operator[](size_t pos)const{
        
        assert(pos < size());
        
        return _start[pos];
    }
    
    iterator insert(iterator pos,const T &x){
        
        assert(pos >= _start && pos <= _finish);
        
        if (_endofstoage == _finish) {
            
            size_t n = pos - _start;
            size_t newCapcity = capacity() == 0 ? 4: capacity() * 4;
            reserve(newCapcity);
            
            pos = _start + n;
        }
 
        //数据移动到数值后面的位置
        iterator end = _finish - 1;
        while (end >= pos) {
            *(end + 1) = *end;
        }
        *pos = x;
        _finish++;
        
        return pos;

    }
    
    void clear(){
        
        _finish = _start;
        
    }
    
    
private:
    iterator _start;
    iterator _finish;
    iterator _endofstoage;
};


}
