/*
 @Date    : 2018-04-18 12:52:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
编译运行命令行g++ -std=c++11 -o 4 4.cpp -lws2_32
 */

#include <stdio.h>
#include <winsock2.h>

// #pragma comment (lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    WSAStartup( MAKEWORD(2, 2), &wsaData);
    printf("wVersion: %d.%d\n", LOBYTE(wsaData.wVersion), HIBYTE(wsaData.wVersion));
    printf("wHighVersion: %d.%d\n", LOBYTE(wsaData.wHighVersion), HIBYTE(wsaData.wHighVersion));
    printf("szDescription: %s\n", wsaData.szDescription);
    printf("szSystemStatus: %s\n", wsaData.szSystemStatus);
    return 0;
}
