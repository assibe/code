//
//  string.hpp
//  string类的模拟实现
//
//  Created by zhourenxi on 2022/8/1.
//

#ifndef string_hpp
#define string_hpp

#include <stdio.h>
#include <assert.h>
#include <string>

#endif /* string_hpp */

namespace zhorenxi {

class string{
    
public:
    
    string(const char* str = "")//拷贝构造
    :_size(strlen(str))
    ,_capacity(_size)
    {
		_str = new char[_capacity + 1];
        strcpy(_str,str);
        
    }
    
    string(const string& s)
    :_size(strlen(s._str))
    ,_capacity(_size)
    {
        _str = new char[_capacity + 1]();
        strcpy(_str, s._str);
        
    }
    
    
	
	~string(){//数据清空
		
		if (_str) {
			
			delete [] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}
		
	}
	
	string& operator=(const string &s){
		
		if (this != &s) {
			
			char* tmp = new char[s._capacity + 1]();
			strcpy(tmp, s._str);
			delete [] _str;
			_str = tmp;
			_size = s._size;
			_capacity = s._capacity;
			
		}
		
		return *this;
		
	}
	
	const char* c_str()const{
		
		return _str;
	
	}
	
	char& operator[](size_t pos){
		
		assert(pos < _size);
		return _str[pos];
		
	}
	
	size_t size()const{
		
		return _size;
	}
	
	size_t capacity()const{
		
		return _capacity;
	}
	
	string& operator+=(char ch){
		
		push_back(ch);
		return *this;
		
	}
	
	string& operator+=(char *ch){
		
		append(ch);
		return *this;
	}
	
	void reserve(size_t n){
		
		if (n > _capacity) {
			
			char *tmp = new char[n + 1]();
			strcpy(tmp, _str);
			delete [] _str;
			_str = tmp;
			
			_capacity = n;
		}
	}
	
	void resize(size_t n,char ch = '\0'){
		
		if (n < _size) {
			
			_size = n;
			_str[_size] = '\0';
		}
		else{
			
			if (n > _capacity) {
				
				resize(n);
			}
			
			for (size_t i = _size; i < n; i++) {
				
				_str[i] = ch;
				
			}
			_size = n;
			_str[_size] = n;
		}
	}
	
	void push_back(char ch){
		
		if (_size == _capacity) {//扩容，进行相关的东西
			
			reserve(_capacity == 0 ? 4 :_capacity * 2);
			
		}
		
		_str[_size] = ch;
		_size++;
		_str[_size] = '\0';
	}
	
	void append(const char* str){
		
		size_t len = _size + strlen(str);
		if (len > _capacity) {
			
			reserve(len);
			
		}
		
		strcpy(_str + _size, str);
		_size = len;
		
	}
	
	void insert(size_t pos,const char* str );
	void earse(size_t pos,size_t len);
	
private:
    
    char * _str;
    size_t _size;  //有效字符个数
    size_t _capacity;  //实际储存有效字符的空间
    
    
};
bool operator<(const string& s1,const string& s2){
	
	return strcmp(s1.c_str(), s2.c_str()) < 0;
	};

   
bool operator==(const string& s1,const string& s2){
	
	return  strcmp(s1.c_str(), s2.c_str()) == 0;
	
};

bool operator>(const string& s1,const string& s2){
	
	return strcmp(s1.c_str(), s2.c_str()) > 0;
	
}

bool operator<=(const string& s1,const string& s2){
	
	return s1 == s2 || s1 < s2;
}

bool operator>=(const string& s1,const string& s2){
	
	return s1 == s2 || s1 > s2;
	
	//重定义了相关的内容！（<,>之前就有)
}

bool operator!=(const string& s1,const string& s2){
	
	return !(s1 == s2);
	
}


}


