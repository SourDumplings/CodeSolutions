/**
 * @file hex2dd.c
 * @author  SourDumplings (changzheng300@foxmail.com)
 * @brief 将 16 进制的 IP 地址转为点分十进制的 IP 地址
 * @version 1.0.0
 * @date 2024-01-22
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 * 编译：gcc -g -Wall hex2dd.c ../csapp.c -o hex2dd -lpthread
 * 
 * 例如：[root@VM-0-11-centos p11.2]# ./hex2dd 0x8002c2f2
128.2.194.242
4072800896
 */

#include "../csapp.h"

int main(int argc, char **argv)
{
    struct in_addr inaddr;  /* Address in network byte order */
    uint32_t addr;          /* Address in host byte order */
    char buf[MAXBUF];       /* Buffer for dotted-decimal string */

    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <hex number>\n", argv[0]);
        exit(0);
    }
    sscanf(argv[1], "%x", &addr);
    inaddr.s_addr = htonl(addr);

    if (!inet_ntop(AF_INET, &inaddr, buf, MAXBUF))
        unix_error("inet_ntop");
    printf("%s\n", buf);
    printf("%u\n", inaddr.s_addr);

    exit(0);
}