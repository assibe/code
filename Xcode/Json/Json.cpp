#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include "/opt/homebrew/Cellar/jsoncpp/1.9.5/include/json/json.h"

using namespace std;

int main(){

    Json::Value val;
    val["姓名"] = "张三";
    val["年龄"] = 32;
    val["成绩"].append(98);
    val["成绩"].append(80);
    val["成绩"].append(93);

    Json::StreamWriterBuilder swb;
    unique_ptr<Json::StreamWriter> sw(swb.newStreamWriter());
    std::ostringstream os;
    sw->write(val,&os);
    std::string str = os.str();
    std::cout << str << std::endl;
    
    return 0;
}


// #include "/usr/include/jsoncpp/json/json.h"
// #include <iostream>
// #include <memory>
// #include <sstream>
// #include <string>
// #include <sstream>//
// #include <iostream>



// int main(int argc,char * agrv[]){
    
//     const char *name = "小明";
//     int age = 18;
//     float score[] = {88.5,43,32,432};
//     Json::Value val;

//     val["姓名"] = name;
//     val["年龄"] = age;
//     for (size_t i = 0; i < sizeof(score) / sizeof(float); i++)
//     {
//         val["年龄"].append(score[i]);
//     }

//     Json::StreamWriterBuilder swb;
//     std::unique_ptr<Json::StreamWriter> sw(swb.newStreamWriter());
//     std::ostringstream os;
//     sw->write(val,&os);
//     std::string str = os.str();
//     std::cout << str << std::endl;
//     return 0;
// }
