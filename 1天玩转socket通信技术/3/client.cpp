/*
 @Date    : 2018-04-17 21:32:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
3.一个简单的Windows下的socket程序-client
Windows 下的 socket 程序依赖 Winsock.dll 或 ws2_32.dll，必须提前加载。
命令行编译参数加上-lws2_32即可，命令行编译命令：
g++ -std=c++11 -o client client.cpp -lws2_32
 */

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>

int main()
{
    //初始化DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //创建套接字
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    //向服务器发起请求
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(1234);
    // connect(sock, (SOCKADDR*)&sockAddr, sizeof(SOCKADDR));
    // connect(sock, reinterpret_cast<SOCKADDR*>(&sockAddr), sizeof(SOCKADDR));
    connect(sock, reinterpret_cast<const sockaddr *>(&sockAddr), sizeof(SOCKADDR));
    //接收服务器传回的数据
    char szBuffer[MAXBYTE] = {0}; // MAXBYTE = 255
    recv(sock, szBuffer, MAXBYTE, NULL);
    //输出接收到的数据
    printf("Message form server: %s\n", szBuffer);
    //关闭套接字
    closesocket(sock);
    //终止使用 DLL
    WSACleanup();
    system("pause");
    return 0;
}
