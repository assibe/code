#include "server.hpp"

void Usage(std::string proc){
std::cerr << "Usage :\n\t" << proc << "port" <<std::endl;
std::cerr << "example" << proc << " 8080\n " << std::endl;
}

int main(int argc,char *argv[]){

if(argc != 2 ){
Usage(argv[0]);
}

uint16_t port = atoi(argv[1]);
ServerTcp svr(port);
svr.init();
svr.loop();
return 0;
}