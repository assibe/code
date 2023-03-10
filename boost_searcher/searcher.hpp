// #pragma searcher_hpp
// #include <util.hpp>
// #include <index.hpp>


#ifndef searcher_hpp
#define search.hpp

#include <util.hpp>
#include <index.hpp>
#include <j>

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
            
            std::JiebaUtil::CutString(query,&words);

        }
    };
    
}