#include<string>
#include<vector>
#include<iostream>

const std::string src_path = "data/input/";
const std::string output = "data/raw_html/raw.txt";

typedef struct DocInfo{
	
	std::string title;
	std::string content;
	std::string url;

}DocInfo_t;

bool EnumFile(const std::string &src_path,std::vector<std::string> *filst_list);
bool ParseHtml(const std::string<std::string> ,) 
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