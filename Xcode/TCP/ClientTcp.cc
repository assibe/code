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

    std::stirng sockaddr server;
    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htonl(serverPort);

   inet_aton(serverIp.c_str(),&server.sin_addr,sizeof(server))

   if(connect(sock,(const struct sockaddr*)&server,sizeof(server)) != 0){

    std::cerr << "connect : " << strerror(errno) << std::endl;
    exit(CONN_ERR);
   }
   std::cout << "info : connect success :" << sock <<std::endl;
   
   std::string message;
   while (!quit){

    message.clear();
    std::cout << "请输入你的消息 >>>";
    std::getline(std::cin,message);
    if(strcasecmp(message.c_str,"quit") == 0)
    quit = true;

    ssize_t s = write(sock,message.c_str,message.size());
    if(s > 0){

        message.resize(1024);
        ssize_t s = read(sock,(char*)(message.c_str),1024);
        if(s > 0){
            message[s] = 0;
            std::cout << "Server Echo>>> " << message << std::endl;

        }
    } 
    else if(s <= 0){
        break;
    }
   }
   close(sock);
   return 0;

}