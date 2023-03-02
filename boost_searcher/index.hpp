#ifndef util__hpp
#define util__hpp 

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cerror>

#endif /* util__hpp */

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

    public: 
        Index(){};
        ~Index(){};

  

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

        return true;
    }
}
