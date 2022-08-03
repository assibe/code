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
	
	
	
    
private:
    
    char * _str;
    size_t _size;  //有效字符个数
    size_t _capacity;  //实际储存有效字符的空间
    
    
};


}

int main(void){
    
    printf("Hello World");
    return 0;
}
