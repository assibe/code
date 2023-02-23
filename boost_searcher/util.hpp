#ifndef util__hpp
#define util__hpp

#include <stdio.h>
#include<iostream>
#include<fstream>
#include<string>

#endif /* util__hpp */


namespace ns_util{
    class FileUtil{
        public:
            static bool ReadFile(const std::string &file_path,std::string *out){
                
                std::ifstream in(file_path,std::ios::in);
                if(in,is_open()){

                    std::cerr <<"open file"<<std::endl;
                    return false;

                }          

                std::string line;
                while(std::getline(line)){
                
                *out += line;

                }
                in.close;
                return true;
            }
    }

}