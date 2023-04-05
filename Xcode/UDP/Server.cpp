#pragma 

#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>
#include <map>
#include <unordered_map>
#include "Log.hpp"
                                    
class Server{

public:
    Server(int port,std::string ip = " "):port_(port),ip_(ip),sockfd_(-1){

    }

    ~Server(){}

public:
    void Init(){
        
        sockfd_ = socket(AF_INET,SOCK_DGRAM,0);
        if(sockfd_ < 0){
            logMessage(FATAL,strerror(errno),sockfd_);
        }
        logMessage(DEBUG,"socket create success : %d",sockfd_);

        struct sockaddr_in local;
        
        local.sin_family = AF_INET;
        local.sin_port = htons(port_);
        local.sin_addr.s_addr = ip_.empty() ? htonl(INADDR_ANY) : inet_addr(ip_.c_str());

        if(bind(sockfd_,(const struct sockaddr*)&local,sockfd_) == -1){
            logMessage(FATAL,"bind %s:%d",strerror(errno),sockfd_);
            exit(2);
        }
        logMessage(DEBUG,"socket bind sucess: %d",sockfd_);

    }

    void start(){
        char inbuffer[1024];
        char outbuffer[1024];
        while (true)
        {
            struct sockaddr_in peer;
            socklen_t len = sizeof(peer);

            ssize_t s = recvfrom(sockfd_,inbuffer,sizeof(inbuffer) - 1,0,(struct sockaddr*)&peer,&len);     

            if(s > 0){
                inbuffer[s] = 0;
            }  
            else if(s == -1){

                logMessage(WARINING,"recvfrom : %d : %d",strerror(errno),sockfd_);
                continue;

            }
            std::string peerIp = inet_ntoa(peer.sin_addr);
            uint32_t peerPort = ntohs(peer.sin_port);
            
        }   
    }
    
private:
    std::string ip_;
    uint16_t port_;
    int sockfd_;
    
};
