#include "util.hpp"

int main(int argc,int *agrv[]){

    if(argc != 3){
        Usage(agrc[0]);
        eit(USAGE_ERR);
    }

    std::string serverPort = atoi(agrv[2]);

    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0){
        std::cerr << "socket : " << strerror(errno) << std::endl;
        exit(SOCKET_ERR);
    }

    
}