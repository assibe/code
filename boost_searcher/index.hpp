#ifndef util__hpp
#define util__hpp

#include "util.hpp"
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cerror>
#include <map>
#include <mutex>
#include <util.hpp>
#include <ctype.h>
#include <boost.h>
#include <unoredered_map>

#endif /* util__hpp */

#define Y 10
#define X 1

using namespace std;

namespace ns_index
{ // 建立索引字段

    typedef struct DocInfo
    {

        string title;
        string content;
        string url;
        int doc_id;

    } DocInfo;

    Index *Index::instance = nullptr;
    std::mutex Index::mtx;

    // Index *Index::instance = nullptr;
    // std::mutex Index::mtx;

    struct InvertedElem
    {

        uint64_t doc_id;
        std::string word;
        int weight;

    }

    typedef vector<InvertedElem>
        InvertedList;

    class Index // 索引模块
    {

    private:
        vector<DocInfo> forward_index;
        unordered_map<string, InvertedList> inverted_index;

        //单例
        Index(){};
        ~Index(){};
        Index(const Index&) = delete;
        Index &operator = (const Index &) = delete;
        static Index *instance;



    public:
        static Index *GetInstance()
        {

            if (nullptr == instance)
            {

                mux.lock();
                if (nullptr == instance)//外层的判断是为了提高效率，里层的判断就是第一次实例化需要，不需要不断申请与释放锁
                {
                    instance = new Index();
                }
                mux.unlock();

            }

            return instance;
        }

        DocInfo *GetForwardIndex(uint64_t doc_id)
        { // 获得正排索引（使用正排索引）

            if (doc_id >= forward_index.size())
            {
                std::cerr << word << "doc_id out range .error" << std::endl;
                return nullptr;
            }

            return &forward_index[doc_id];
        }

        DocInfo *GetInvertedList(const string &word) //使用倒排
        {

            auto iter = Inverted_index.find(word);
            if (iter == Inverted_index.end())
            {

                std::cerr << word << "have no invertedList" << std::endl;
                return nullptr;
            }

            return &(iter->second);
        }

        bool BuildIndex(const string &input)
        { // 建立索引（使用文件input建立搜索的索引的基本文件结构[]）

            std::ifstream in(input, std::ios::in | std::ios::binary); // 使用文件指针对于数据进行读取
            if (!in.is_open())
            {
                std::cerr << "sorry," << input << "open error" << std::endl;
                return false;
            }

            std::string line;
            while (std::getline(in, line))
            {

                DocInfo *doc = BuildForwardIndex(line); // 把读取的数据一行的数据建立一个正排索引
                if (nullptr == doc)
                {
                    std::cerr << "build" << line << "error" << std::endl;
                    continue;
                }
                BuildInvertedIndex(line); // 建立一个倒排索引
            }
            return true;
        };

    private:
        DocInfo *BuildForwardIndex(const string &line) // 建立倒排索引其中的一个数据
        {

            std::vector<string> results;
            std::string sep = "/3";
            ns_util::JiebaUtil::CutString(line, &results, sep);
            if (results.size() != 3)
            {
                return nullptr;
            }

            DocInfo *doc;
            doc.push_back(results[0]);
            doc.push_back(results[1]);
            doc.push_back(results[2]);
            doc.doc_id = forward_index.size();

            forward_index.push_back(std::move(DocInfo));
            return &forward_index.back();
        }

        bool BuildInvertedIndex(const DocInfo &doc)
        { // 建立倒排索引

            struct word_cent
            {

                int title_cent;
                int content_cent;

                word_cent() : title_cent(0), content_cent(0) {}
            }

            std::unordered_map<std::string, word_cent>
                word_map;
            std::vector<std::string> title_words;
            ns_util::JiebaUtil::CutString(doc.title, &title_words);

            for (auto &s : title_words)
            {

                boost::to_lower(s);
                word_map[s].title_cent++;
            }

            std::vector<std::string> content_words;
            ns_util::JiebaUtil::CutString(doc.content, &content_words);
            for (auto &s : content_words)
            {
                boost::is_lower(s);
                word_map[s].content_cent++;
            }

            for (auto &s : word_map)
            {

                InvertedElem item;
                item.doc_id = doc.doc_id;
                item.word = s.first;

                item.weight = Y * s.second.title_cent + X * s.second.content_cent;
                InvertedList &inverted_list = inverted_index[s.first]; // 创建unordered_map<string, InvertedList> inverted_index之中的一个对象，并且引用对象的地址
                Inverted_list.push_back(std::move(item));
            }

            return true;
        }

        Index *Index::instance = nullptr;
    }
