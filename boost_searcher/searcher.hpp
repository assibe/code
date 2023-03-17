// #pragma searcher_hpp
// #include <util.hpp>
// #include <index.hpp>


#ifndef searcher_hpp
#define search.hpp

#include <util.hpp>
#include <string>
#include <index.hpp>
#include <vector>

#endif




namespace ns_searcher{

    class Searcher
    {
    private:

    ns_index::Index *index;
        /* data */
    public:
        Searcher(/* args */);
        ~Searcher();

        void Initsearcher(const std::string &input){

            index = ns_index::Index::GetInstance();

            index->BuildIndex(input);
        }

        void Searcher(const std::string &query,std::string *json_string){
            
            std::vector <std::string> words;
            std::JiebaUtil::CutString(query,&words);

            ns_index::InvertedList inverted_list_all;
            for(std::string word: words){

                boost::to_lower(word); 
                ns_index::InvertedList *inverted_list = index -> GetInvertedList(word);
                if(nullptr == inverted_list){
                    continue;
                    
                }
                inverted_list_all.insert(inverted_list_all.end(),inverted_list.begin(),inverted_list.end(),
                [](const ns_index::InvertedElem &e1,const ns_index::InvertedElem &e2){
                    e1.weight > e2.weight}
                );
            }

            for(auto &item : inverted_list_all){
                
                ns_index::DoInfo *doc = index->GetForwardIndex(item,doc_id);
                if(nullptr == doc){
                    continue;
                }

            //第27节课的位置
            }

        }
    };
    
}