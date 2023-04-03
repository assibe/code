#include "util.hpp"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pthread.h>
#include<netinet/in.h>
#include <cstring>



class ServerTcp{

public:
    ServerTcp(uint16_t port, const std::string &ip = "") : port_(port), ip_(ip), listenSock_(-1){}
    ~ServerTcp(){}

    

public:

    void init(){
        listenSock_ = socket(AF_INET,SOCK_STREAM,0);//创建socket

        if(listenSock_ < 0){

            logMessage(FATAL,"socket:%s",strerror(errno));
            exit(SOCKET_ERR);

        }
        logMessage(DEBUG,"listen: %s, &d",strerror(errno),listenSock_);

        struct sockaddr_in local;
        memset(&local,0,sizeof(local));
        local.sin_family = AF_INET;
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

    while(true){

        struct sockaddr_in peer;
        socklen_t len = sizeof(peer);
        int serviceSock = accept(listenSock_,(struct sockaddr*)&peer,&len);
        
        if(serviceSock < 0){
            logMessage(WARINING,"accept: %s[%d]",strerror(errno),serviceSock);
            continue;
        }

        uint16_t peerPort =  ntohs(peer.sin_port);
        std::string peerIp = inet_ntoa(peer.sin_addr);
        logMessage(DEBUG,"accept: %s | %s[%d],socket fd:%d",strerror(errno),peerPort,serviceSock);
        
        pid_t id = fork();
        if(id == 0){
            
            close(listenSock_);
            if(id > 0){
                transService(serviceSock,peerIp,peerPort);
                exit(0);
            }
        }
        close(serviceSock);
        pid_t ret = waitpid(id,nullptr,0);
        assert(ret>0);

    }

}

void transService(int sock, const std::string &clientIp, uint16_t clientPort){
        assert(sock >= 0);
        assert(!clientIp.empty());
        assert(clientPort >= 1024);

        char inbuffer[BUFFER_SIZE];
        while (true)
        {
            ssize_t s = read(sock, inbuffer, sizeof(inbuffer) - 1); //我们认为我们读到的都是字符串
            if (s > 0)
            {
                // read success
                inbuffer[s] = '\0';
                if(strcasecmp(inbuffer, "quit") == 0)
                {
                    logMessage(DEBUG, "client quit -- %s[%d]", clientIp.c_str(), clientPort);
                    break;
                }
                logMessage(DEBUG, "trans before: %s[%d]>>> %s", clientIp.c_str(), clientPort, inbuffer);
                // 可以进行大小写转化了
                for(int i = 0; i < s; i++)
                {
                    if(isalpha(inbuffer[i]) && islower(inbuffer[i])) 
                        inbuffer[i] = toupper(inbuffer[i]);
                }
                logMessage(DEBUG, "trans after: %s[%d]>>> %s", clientIp.c_str(), clientPort, inbuffer);

                write(sock, inbuffer, strlen(inbuffer));
            }
            else if (s == 0)
            {
                // pipe: 读端一直在读，写端不写了，并且关闭了写端，读端会如何？s == 0，代表对端关闭
                // s == 0: 代表对方关闭,client 退出
                logMessage(DEBUG, "client quit -- %s[%d]", clientIp.c_str(), clientPort);
                break;
            }
            else
            {
                logMessage(DEBUG, "%s[%d] - read: %s", clientIp.c_str(), clientPort, strerror(errno));
                break;
            }
        }

        // 只要走到这里，一定是client退出了，服务到此结束
        close(sock); // 如果一个进程对应的文件fd，打开了没有被归还，文件描述符泄漏！
        logMessage(DEBUG, "server close %d done", sock);
    };

private:
    int listenSock_;
    u_int16_t port_;
    std::string ip_;

};


    static void Usage(std::string proc){
        std::cerr << "Usage:\n\t" << proc << "port ip" << std::endl;
        std::cerr << "example\n\t" << proc << "8080 127.0.0.1\n" << std::endl; 
    }

int main(int argc,char *argv[]){

    if(argc != 2 && argc != 3){
        Usage(argv[0]);
        exit(USAGE_ERR);
    }

    uint16_t port = atoi(argv[1]);
    std::string ip;
    if(argc == 3){
        ip = argv[2];
    }


    ServerTcp svr(port,ip);
    svr.init();
    svr.loop();
    return 0;
}


