/*
 @Date    : 2018-04-17 20:02:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
io缓冲区实验
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;

    if ((fp = fopen("output.txt", "w")) == NULL)
    {
        perror("打开文件失败，原因是");
        exit(EXIT_FAILURE);
    }

    fputs("I love FishC.com!\n", fp);
    getchar();

    fclose(fp);
    return 0;
}
