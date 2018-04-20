/*
 @Date    : 2018-04-20 10:25:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
21.基于UDP的服务器端和客户端
 */

#include <stdio.h>
#include <winsock2.h>
#include <cstring>

// #pragma comment (lib, "ws2_32.lib")  //加载 ws2_32.dll

#define BUF_SIZE 100

int main()
{
    WSADATA wsaData;
    WSAStartup( MAKEWORD(2, 2), &wsaData);
    //创建套接字
    SOCKET sock = socket(AF_INET, SOCK_DGRAM, 0);
    //绑定套接字
    sockaddr_in servAddr;
    memset(&servAddr, 0, sizeof(servAddr));  //每个字节都用0填充
    servAddr.sin_family = PF_INET;  //使用IPv4地址
    servAddr.sin_addr.s_addr = htonl(INADDR_ANY); //自动获取IP地址
    servAddr.sin_port = htons(1234);  //端口
    bind(sock, reinterpret_cast<SOCKADDR*>(&servAddr), sizeof(SOCKADDR));
    puts("The server is ready...");
    //接收客户端请求
    SOCKADDR clntAddr;  //客户端地址信息
    int nSize = sizeof(SOCKADDR);
    char buffer[BUF_SIZE];  //缓冲区
    while (1)
    {
        recvfrom(sock, buffer, BUF_SIZE, 0, &clntAddr, &nSize);

        // 处理数据
        if (strcmp(buffer, "end") == 0)
        {
            puts("program ended.");
            break;
        }
        char result[BUF_SIZE+100];
        sprintf(result, "\"%s\" is processed.", buffer);
        int resultLen = strlen(result);

        sendto(sock, result, resultLen, 0, &clntAddr, nSize);
    }
    closesocket(sock);
    WSACleanup();
    return 0;
}
