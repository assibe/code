#pragma
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <utility>
#include <stdlib.h>
#include <sys/stat.h>
#include "jsoncpp/json/json.h"
#include <sstream>
#include<memory>

namespace aod
{
    class FileUtil
    {
    private:
        std::string _name; // 路径名

    public:
        FileUtil(const std::string name) : _name(name){}; // 初始化成员变量

        bool Exists()
        {

            int ret = access(_name.c_str(), F_OK);
            if (ret != 0)
            {
                std::cout << "文件不存在" << std::endl;
                return false;
            }
            return true;
        } // 文件存在

        size_t Size()
        {

            if (this->Exists() == false)
            {
                /* code */
                return false;
            }

            struct stat st;
            int ret = stat(_name.c_str(), &st);
            if (ret != 0)
            {
                /* code */
                std::cout << "文件的大小获取失败" << std::endl;
                return 0;
            }

            return st.st_size;
        } // 文件大小

        bool GetContent(std::string *body)
        {

            std::ifstream ifs;
            ifs.open(_name, std::ios::binary);
            if (ifs.is_open() == false)
            {

                std::cout << "获得文件失败" << std::endl;
                return 0;
            }
            size_t flen = this->Size();
            body->resize(flen);

            ifs.read(&(*body)[0], flen);
            if (ifs.good() == false)
            {
                std::cout << "获得文件失败" << std::endl;
                ifs.close();
                return false;
            }

            ifs.close();
            return true;
        } // 获取文件内容

        bool SetContent(std::string *body)
        {
            std::ofstream ofs;
            ofs.open(_name, std::ios::binary);

            if (ofs.is_open() == false)
            {

                std::cout << "打开失败";
                ofs.close();
                return false;
            }

            ofs.write(body->c_str(), body->size());
            if (ofs.good() == false)
            {
                std::cout << "写入失败";
                ofs.close();
                return false;
            }

            ofs.close();
            return true;
        }; // 写入文件内容

        bool CreateDirectory()
        {

            if (this->Exists())
            {
                return 0;
            }

            mkdir(_name.c_str(), 0777);
            return true;
        } // 创建文件夹
    };

    	class JsonUtil{
		public:
			static bool Serialize(const Json::Value &value, std::string *body) {
				Json::StreamWriterBuilder swb;
				std::unique_ptr<Json::StreamWriter> sw(swb.newStreamWriter());

				std::stringstream ss; 
				int ret = sw->write(value, &ss);
				if (ret != 0) {
					std::cout << "Serialize failed!\n";
					return false;
				}   
				*body = ss.str();
				return true;
			}
			static bool UnSerialize(const std::string &body, Json::Value *value) {
				Json::CharReaderBuilder crb;
				std::unique_ptr<Json::CharReader> cr(crb.newCharReader());

				std::string err;
				bool ret = cr->parse(body.c_str(),body.c_str() + body.size(), value, &err);
				if (ret == false) {
					std::cout << "UnSerialize failed!\n";
					return false;
				}
				return true;
			}
	};
}