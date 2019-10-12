/*
 @Date    : 2018-04-19 14:34:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
11.数据的粘包问题演示
 */

#include <stdio.h>
#include <windows.h>
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
    char buffer[BUF_SIZE] = {0};  //缓冲区
    SOCKET clntSock = accept(servSock, reinterpret_cast<SOCKADDR*>(&clntAddr), &nSize);
    Sleep(10000);  //注意这里，让程序暂停10秒，
    // 目的是为了演示粘包现象，客户端在10秒内把所有的数据都发过来了
    //接收客户端发来的数据
    recv(clntSock, buffer, BUF_SIZE, 0);

    // 处理数据
    int infoL;
    char resultBuffer[BUF_SIZE+100];
    sprintf(resultBuffer, "\"%s\" has been processed by the server.\n", buffer);
    infoL = strlen(resultBuffer);

    send(clntSock, resultBuffer, infoL, 0);
    //关闭套接字并终止DLL的使用
    closesocket(clntSock);
    closesocket(servSock);
    WSACleanup();
    return 0;
}
