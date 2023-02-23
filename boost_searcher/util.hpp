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
                if(in.is_open()){

                    std::cerr <<"open file"<<std::endl;
                    return false;

                }          

                std::string line;
                while(std::getline(in,line)){


                *out += line;

                }
                in.close();
                return true;
            }
    }

}

static bool ParseContent(const std::string &file,std::string *content){

    enum{
        LABLE;
        CONTENT;
    };

    enum status s = LABLE;
    for(char c:file){
        switch(s){
            case LABLE:
            if(c == '>') s = CONTENT;;
            break;
            }

            case CONTENT:
            if(c == '<')
             s = LABLE;
            else{

                if(c == '\n') c = ' ' ;
                content->push_back(c);  
            }
            break;
            default:
                break;

        }
    }
    return true;
}

static bool ParseHtml(const std::string &file_path,std::string *url){

        std::string tail_head = "https://www.boost.org/doc/libs/1_78_0/doc/html";
                std::string tail = file_path.substr(src_path.size());

                *url = _url_head + url_tail;
                return true;
        }