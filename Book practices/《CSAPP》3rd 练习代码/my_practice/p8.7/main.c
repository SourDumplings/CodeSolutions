/*
 * @Author: SourDumplings
 * @Date: 2023-09-14 14:45:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: 编译： gcc -g -Wall main.c ../csapp.c -o main -lpthread
 */

#include "../csapp.h"

void handler(int sig)
{
    return;
}

unsigned int snooze(unsigned int secs)
{
    unsigned int rc = sleep(secs);
    printf("Sleep for %d of %u secs. \n", secs - rc, secs);
    return rc;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s <secs>\n", argv[0]);
        exit(0);
    }

    if (signal(SIGINT, handler) == SIG_ERR)
    {
        unix_error("signal error\n");
    }
    (void)snooze(atoi(argv[1]));
    exit(0);
    return 0;
}
