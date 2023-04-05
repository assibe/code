#pragma 

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <unistd.h>

    struct sockaddr_in server;//进行线程分离防止内容被释放

static void Usage(std::string name){

    std::cout << "Usage:\n\t" << name << "server_ip server_port" << std::endl;

}

int main(int argc,char *argv[ ]){

    if(3 !=  argc){
        Usage(argv[0]);
    }

    std::string server_ip = argv[1];
    uint16_t server_port = atoi(argv[2]);

    int sockfd = socket(AF_INET,SOCK_DGRAM,0);
    assert(sockfd >  0);

    // struct sockaddr_in serve;


    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(server_ip.c_str());
    server.sin_port = htons(server_port);
    
        
        // local.sin_family = AF_INET;
        // local.sin_port = htons(port_);
        // local.sin_addr.s_addr = ip_.empty() ? htonl(INADDR_ANY) : inet_addr(ip_.c_str());
        close(sockfd);
        return 0;
}