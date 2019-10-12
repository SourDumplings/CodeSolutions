/*
 @Date    : 2018-04-20 10:06:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
19.在socket中使用域名
 */

#include <stdio.h>
#include <stdlib.h>
#include <winsock2.h>

// #pragma comment(lib, "ws2_32.lib")

int main()
{
    WSADATA wsaData;
    WSAStartup( MAKEWORD(2, 2), &wsaData);
    struct hostent *host = gethostbyname("www.baidu.com");
    if (!host)
    {
        puts("Get IP address error!");
        system("pause");
        exit(0);
    }
    //别名
    for (int i = 0; host->h_aliases[i]; i++)
    {
        printf("Aliases %d: %s\n", i + 1, host->h_aliases[i]);
    }
    //地址类型
    printf("Address type: %s\n", (host->h_addrtype == AF_INET) ? "AF_INET" : "AF_INET6");
    //IP地址
    for (int i = 0; host->h_addr_list[i]; i++)
    {
        printf("IP addr %d: %s\n", i + 1, inet_ntoa( *(struct in_addr*)host->h_addr_list[i] ) );
    }
    system("pause");
    return 0;
}
