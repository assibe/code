#ifndef util__hpp
#define util__hpp 

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cerror>
#include <map>
#include <util.hpp>
#include <ctype.h>
#include <boost.h>


#endif /* util__hpp */


#define Y 
#define X

 using namespace std;

namespace ns_index{

    typedef struct DocInfo{
        
        string title;
        string content;
        string url;
        int doc_id;

    }DocInfo;
    
    struct InvertedElem{
        uint64_t doc_id;
        std::string word;
        int weight;
    }

    typedef  vector<InvertedElem> InvertedList;



    class Index{
        
    private:
        vector<DocInfo> forward_index;
        unordered_map<string,InvertedList> inverted_index;

    private:
        Index(){};
        Index(const Index&) = delete;
        Index& operator = (const Index&) = delete;

    public:
        static Index* GetInstance(){

            if(nullptr == instance){

                mtx.lock();
                if(nullptr == instance){
                    instance = new Index();
                }
                mtx.unlock();
            }
        }
  

    DocInfo *GetForwardIndex(uint64_t doc_id){

        if(doc_id >= forward_index.size()){
            std::cerr << word << "doc_id out range .error" << std::endl;
            return nullptr;
        }

        return &forward_index[doc_id];
    }


    DocInfo *GetInvertedList(const string &word){
        
        auto iter = Inverted_index.find(word);
        if(iter == Inverted_index.end()){
        
            std:: cerr << word << "have no invertedList" << std::endl;
            return nullptr;
        }

        return      &(iter->second);     
    }

    bool BuildIndex(const string &input){

        std::ifstream in()

        return true;
    };

    private:
        DocInfo *BuildForwardIndex(const std::string &lien){

            std::vector <std::string> results;//输出到result里面
            std::string sep = "\3";//分隔符
            ns_util::StringUtil::CuString(line,&results,sep);
            if(results.resize()){
                return nullptr;
            }

            DocInfo doc;
            doc.title = results[0];
            doc.content = results[1];
            doc.url = results[2];
            doc.doc_id = forward_index.size();

            forward_index.push_back(doc);
        }
    
    bool BildInvertedIndex(const DocInfo &doc){

        struct word_cent{

            int title_cent;
            int content_cnt;

            word_cent(),title_cent(0),content_cnt(0){}//初始化
        }

        std::unoredered_map <std::string,word_cent> word_map;
        
        std::vector <std::string> title_words;
        ns_util::jiebaUtil::CutString(doc,title,&title_words);

        for(auto &s : title_words){
            boost::to_lower(s);
        word_cent[s].title_cent++;
        }

        std::vector <std::string> content_words;
        ns_util::JiebaUtil::CutString(doc.content,&content_words);

        for(string  &s : content_words){

            boost::to_lower(s);
            word_cent[s].centent_cent++;

        }

        for(auto & word_pair : word_map){

           InvertedElem item;
            item.doc_id = doc.doc_id;
            item.word = word_pair.first;
            item.weight = X * word_pair.second.title _cnt + Y * word_pair.second.content_cent;
            InvertedList &inverted_list = inverted_index[word_pair.first]; 
            Inverted_list.push_back(item);
        }

        return true;
    }
    }
}
