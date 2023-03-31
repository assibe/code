#include"log.hpp"
#include<signal.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<pthread.h>
#include<string>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include <cstring>


class ServerTcp{

public:

    void init(){
        listenSock_ = socket(AF_INET,SOCK_DGRAM,0);
        if(listenSock_ < 0){

            logMessage(FATAL,"socket:%s",strerror(errno));
            exit(SOCKET_ERR);

        }
        logMessage(DEBUG,"listen: %s, &d",strerror(errno),listenSock_);

        struct sockaddr_in local;
        memset(&local,0,sizeof(local));
        local.sin_family = PF_INET;
        local.sin_port = htons(port_);
        ip_.empty() ? (local.sin_addr.s_addr = INADDR_ANY) : (inet_aton(ip_.c_str(),&local.sin_addr));

        if(bind(listenSock_,(const struct sockaddr*)&local,sizeof(local)) < 0){
            logMessage(FATAL,"bind: %s",strerror(errno),listenSock_);
            exit(BIND_ERR);
        }
        logMessage(DEBUG,"bind: %s , %d ",strerror(errno),listenSock_);
        
        if(listen(listenSock_,5) < 0){
            logMessage(FATAL,"listen:%s",strerror(errno));
            exit(LISTEN_ERR);
        }
        logMessage(DEBUG,"listen:%s, %d",strerror(errno),listenSock_);
    }

    void loop(){
        
    }

private:
    int listenSock_;
    u_int16_t port_;
    std::string ip_;
}