/*
 @Date    : 2018-04-17 20:08:57
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
io缓冲设置
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char buff[1024];

    memset(buff, '\0', sizeof(buff));

    // setvbuf(stdout, buff, _IOFBF, 1024);
    setvbuf(stdout, buff, _IONBF, 1024);

    fprintf(stdout, "Welcome to bbs.fishc.com\n");

    fflush(stdout);

    fprintf(stdout, "输入任意字符后才会显示该行字符！\n");

    getchar();

    return 0;
}
