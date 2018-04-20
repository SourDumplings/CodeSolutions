/*
 @Date    : 2018-04-18 16:07:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
10.实现迭代服务器端和客户端
客户端输入一行字符串，
服务器端计算出这一行字符串的长度返回给客户端
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
    SOCKET servSock = socket(AF_INET, SOCK_STREAM, 0);
    //绑定套接字
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;  //使用IPv4地址
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");  //具体的IP地址
    sockAddr.sin_port = htons(1234);  //端口
    bind(servSock, reinterpret_cast<SOCKADDR*>(&sockAddr), sizeof(SOCKADDR));
    //进入监听状态
    listen(servSock, 20);
    printf("The server is listening...\n");
    //接收客户端请求
    SOCKADDR clntAddr;
    int nSize = sizeof(SOCKADDR);
    char buffer[BUF_SIZE];  //缓冲区

    while (true)
    {
        SOCKET clntSock = accept(servSock, reinterpret_cast<SOCKADDR*>(&clntAddr), &nSize);

        recv(clntSock, buffer, BUF_SIZE, 0);  //接收客户端发来的数据

        // 处理数据
        int l = strlen(buffer);
        char lInfo[BUF_SIZE];
        int strLen;
        bool end = false;
        if (strcmp(buffer, "end"))
        {
            sprintf(lInfo, "The length of the input line is %d\n", l);
            strLen = strlen(lInfo);
        }
        else
        {
            strcpy(lInfo, "endConnection");
            strLen = strlen("endConnection");
            end = true;
        }

        lInfo[strLen] = '\0';
        printf("%s is sent from the server\n", lInfo);
        send(clntSock, lInfo, strLen+1, 0);  //返回接受的数据长度信息

        closesocket(clntSock); // 关闭套接字
        if (end)
        {
            break;
        }
        memset(buffer, 0, BUF_SIZE); // 重置缓冲区
    }

    //关闭套接字
    closesocket(servSock);
    //终止 DLL 的使用
    WSACleanup();
    return 0;
}

