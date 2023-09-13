#ifndef Data_hpp
#define Data_hpp
#include "util.hpp"
#include <mysql/mysql.h>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include "jsoncpp/json/json.h"
#include <string>
#include <stdio.h>
#include <mysql/mysql.h>


namespace aod
{

#define HOST "127.0.0.1"
#define USER "root"
#define PASS "MyNewPass4!"
#define NAME "aod_system"

    static MYSQL *MysqlInit()
    {

        MYSQL *mysql = mysql_init(NULL);
        if (mysql == NULL)
        {
            std::cout << "初始化失败";
            return NULL;
        }

        if (mysql_real_connect(mysql, HOST, USER, PASS, NAME, 0, NULL, 0) == NULL)
        {
            std::cout << "连接mysql服务器失败";
            mysql_close(mysql);
            return NULL;
        }
        mysql_set_character_set(mysql, "utf-8");
        return mysql;
    } // 初始化

    static void MysqlDestroy(MYSQL *mysql)
    {
        if (mysql != NULL)
        {
            mysql_close(mysql);
        }
    } // 关闭数据库API

    static bool MysqlQuery(MYSQL *mysql, const std::string &sql)
    {

        int ret = mysql_query(mysql,sql.c_str());
        if (ret != 0)
        {
            std::cout << sql << "语句执行错误\n" <<std::endl;
            std::cout << mysql_error(mysql) << std::endl;

            return false;
        }
        return true;

    } // 执行mysql语句

    class TableVideo
    {

    private:
        MYSQL *_mysql;
        std::mutex _mutex;

    public:
        TableVideo()
        {
            _mysql = MysqlInit();
            if (_mysql == NULL)
            {
                exit(-1);
            }
        }

        ~TableVideo()
        {
            MysqlDestroy(_mysql);
        }

bool Insert(const Json::Value &video) {
				//id name info video image
				std::string sql;
				sql.resize(4096 + video["info"].asString().size());//防止简介过长
				#define INSERT_VIDEO "insert tb_video values(null, '%s', '%s', '%s', '%s');"
				if (video["name"].asString().size() == 0) {
					return false;
				}
				//要完成的细致的话需要对各个数据进行校验，因为不校验直接用就有可能出问题
				sprintf(&sql[0], INSERT_VIDEO, video["name"].asCString(),
						video["info"].asCString(), 
						video["video"].asCString(),
						video["image"].asCString());
				return MysqlQuery(_mysql, sql);
			}
        bool Update(int video_id, const Json::Value &video)
        {

            std::string sql;
            sql.resize(4096 + video["info"].asString().size());
#define UPDATE_VIDEO "update tb_video set name = '%s',info='%s' "
            sprintf(&sql[0], UPDATE_VIDEO, video["name"].asCString(), video["info"].asCString(), video_id);
            return MysqlQuery(_mysql, sql);
        }

        bool Delete(int video_id)
        {

#define DELETE_IVDEO "delete from tb_video where id = %d;"
            char sql[1024] = {0};
            sprintf(sql, DELETE_IVDEO, video_id);

            return MysqlQuery(_mysql, sql);
        }

        bool SelectAll(Json::Value *videos)
        {

#define SELECTALL "select * from tb_video;"
            _mutex.lock();
            std::string sql[1024];
            bool ret = MysqlQuery(_mysql,SELECTALL);
            if (ret == false)
            {
                _mutex.unlock();
                return false;
            }

            MYSQL_RES *res = mysql_store_result(_mysql);
            if (res == nullptr)
            {
                std::cout << "获取内容失败";
                _mutex.unlock();
                return false;
            }

            _mutex.unlock();
            int num_rows = mysql_num_rows(res);
            for (size_t i = 0; i < num_rows; i++)
            {
                MYSQL_ROW row = mysql_fetch_row(res);
                Json::Value video;
                video["name"] = atoi(row[0]);
                video["info"] = row[1];
                video["video"] = row[2];
                video["image"] = row[3];
                videos->append(video);
            }            

            mysql_free_result(res);
            return true;
        }
        bool SelectOne(int video_id, Json::Value *video)
        {

#define SELECTONE_VIDEO "select * from tb_video where id = %d;"
            char sql[1024] = {0};
            sprintf(sql, SELECTONE_VIDEO, video_id);

            _mutex.lock();
            bool ret = MysqlQuery(_mysql, sql);
            if (ret == false)
            {
                _mutex.unlock();
                return false;
            }

            MYSQL_RES *res = mysql_store_result(_mysql);

            if (res == NULL)
            {
                _mutex.unlock();
                std::cout << "获取结果失败";
                return false;
            }

            int num_rows = mysql_num_rows(res);
            if (num_rows != 1)
            {
                std::cout << "数据为空";
                mysql_free_result(res);
                return false;
            }; // 验证数据是否存在

            MYSQL_ROW row =  mysql_fetch_row(res);
            (*video)["id"] = video_id;
            (*video)["name"] = row[1];
            (*video)["info"] = row[2];
            (*video)["video"] = row[3];
            (*video)["image"] = row[4];

            mysql_free_result(res);
            return true;
        }

        bool SelectLike(const std::string &key, Json::Value *videos)
        {

#define SELECTONE_Like "select * from tb_video where name like '%%%s%%';"
            char sql[1024] = {0};
            sprintf(sql,SELECTONE_Like, key.c_str());

            _mutex.lock();
            bool ret = MysqlQuery(_mysql, sql);
            if (ret == false)
            {
                _mutex.unlock();
                return false;
            }

            MYSQL_RES *res = mysql_store_result(_mysql);

            if (res == NULL)
            {
                _mutex.unlock();
                std::cout << "获取结果失败";
                return false;
            }
            _mutex.unlock();

            int num_rows = mysql_num_rows(res);
            if (num_rows != 1)
            {
                std::cout << "数据为空";
                mysql_free_result(res);
                return false;
            } // 验证数据是否存在

            for (int i = 0; i < num_rows; i++)
            {
                MYSQL_ROW row = mysql_fetch_row(res);
                Json::Value video;
                video["id"] = atoi(row[0]);
                video["name"] = row[1];
                video["info"] = row[2];
                video["video"] = row[3];
                video["image"] = row[4];
                videos->append(video);
            }

            mysql_free_result(res);
            return true;
        }
    };
}

#endif

