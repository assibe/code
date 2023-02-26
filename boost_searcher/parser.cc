#include<string>
#include<vector>
#include<iostream>
#include"util.hpp"
#include<boost/filesystem.hpp>

using namespace std;

const std::string src_path = "data/input/";
const std::string output = "data/raw_html/raw.txt";

typedef struct DocInfo{
	
	std::string title;
	std::string content;
	std::string url;

}DocInfo_t;


bool EnumFile(const std::string &src_path,std::vector<std::string> *filst_list);
bool ParseHtml(const std::vector<std::string> &files_list,std::vector<DocInfo_t> *reselts) ;
bool SaveHtml(const DocInfo_t  &results,const std::string &output);


int main(){
	
	std::vector<std::string> filst_list;
	if(!EnumFile(src_path,&filst_list)){
		
		std::cerr<<"EnumFile faile" << std::endl;
		return 1;
	}

	DocInfo_t results;	
	if(!ParseHtml(filst_list,results)){
		std::cerr << "parse html error" << std::endl;
		return 2;
	}

	if(!SaveHtml(results,output)){
		std::cerr << "save error";
		return 3;
	}
	
	return 0;
}

bool EnumFile(const std::string &src_path,std::vector<std::string> *files_list){
	namespace fs = boost::filesystem;
	fs::path root_path(src_path);	
	if(boost::filesystem::exists(root_path)){

		std::cerr<< src_path <<"not exists" << std::endl;
		return false;
	
	}

	boost::filesystem::recursive_directory_iterator end;
	for(boost::filesystem::recursive_directory_iterator iter(root_path);iter != end;iter++){
		if(boost::filesystem::is_regular_file(*iter)){
			continue;
		}

		if(iter->path().extension() != ".html"){
			continue;
		}

	}
	
	files_list->push_back(iter->path().string());

	}

bool ParseHtml(const std::vector<std::string> &files_list,std::vector<DocInfo_t> *reselts){
	
	for(const std::string &file:files_list){
		
		std::string results;
		if(!ns_util::FileUtil::ReadFile(file,&results)){
			continue;
		}

		DocInfo_t doc;

		if(!ParseTitle(results,&doc.title)){
			continue;
		}

		if(!ParseContent(results,&doc.content))	{

			continue;
		}

		if(!ParseUrl()){
			continue;
		}
		
		results->push_back(move(doc));
		}

	return true;
	}

	



bool SaveHtml(const DocInfo_t  &results, const std::string &output){

	#define SEP '\3'
	ofstream out(output,std::ios::put | std::ios::binary);
	if(!out.is_open()){
		std::cerr << "open" << output << "failed" <<std::endl;
		return false;
	}

	for(auto &item : results){
		
		std::string out_string;
		out_string = item.title;
		out_string += SEP;
		out_string += item.content;
		out_string += item.url; 

	}

	out.close;
	return true;
}