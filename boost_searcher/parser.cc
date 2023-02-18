#include<stdio.h>
#include<string>
#include<vector>
#include<cerr>

const std::string src_path="data/input"
const std::string raw = "data/output/raw.txt"

typedef struct DocInfo{

	std::string title;
	std::string content;
	std::string url;
}DocInfo;

int main(){
	std::vector<std::string> file_list;
	
	if(!EnumFile(src_path,&file_list)){//c储存
		std::cerr << "enum file name errors" << std::endl;
		return 1;
	}

	std::vector<DocInfo> result;
	if(!ParseHetml(file_list,result)){

		std::cerr << "parase html error" << std::endl;
		return 2;
	}
	if(!SaveHtml(result,&output)){
		std::cerr<< "save html error";
		return 3;
	}

}

bool EnumFile(const std::string &src_path,std::string *file_list){

	
}