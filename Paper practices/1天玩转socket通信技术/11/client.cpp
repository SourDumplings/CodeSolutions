/*
 @Date    : 2018-04-19 14:36:53
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
11.数据的粘包问题演示
 */

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <windows.h>
// #pragma comment(lib, "ws2_32.lib")  //加载 ws2_32.dll
#define BUF_SIZE 100

int main()
{
    //初始化DLL
    WSADATA wsaData;
    WSAStartup(MAKEWORD(2, 2), &wsaData);
    //向服务器发起请求
    sockaddr_in sockAddr;
    memset(&sockAddr, 0, sizeof(sockAddr));  //每个字节都用0填充
    sockAddr.sin_family = PF_INET;
    sockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    sockAddr.sin_port = htons(1234);
    //创建套接字
    SOCKET sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    connect(sock, reinterpret_cast<SOCKADDR*>(&sockAddr), sizeof(SOCKADDR));
    //获取用户输入的字符串并发送给服务器
    char bufSend[BUF_SIZE] = {0};
    printf("Input a string: ");
    gets(bufSend);
    for (int i = 0; i < 3; i++)
    {
        send(sock, bufSend, strlen(bufSend), 0);
    }
    //接收服务器传回的数据
    char bufRecv[BUF_SIZE] = {0};
    recv(sock, bufRecv, BUF_SIZE, 0);
    //输出接收到的数据
    printf("Message form server: %s\n", bufRecv);
    closesocket(sock);  //关闭套接字
    WSACleanup();  //终止使用 DLL
    system("pause");
    return 0;
}

