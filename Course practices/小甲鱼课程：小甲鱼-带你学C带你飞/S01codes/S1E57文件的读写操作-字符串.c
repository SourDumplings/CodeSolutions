/*
 @Date    : 2018-04-16 19:55:55
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
文件的读写操作，字符串
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

int main(int argc, char const *argv[])
{
    FILE *fp;
    char buffer[MAX];

    if ((fp = fopen("lines.txt", "w")) == NULL)
    {
        printf("打开文件失败！\n");
        exit(EXIT_FAILURE);
    }

    fputs("Line one: Hello World!\n", fp);
    fputs("Line two: Hello FishC!\n", fp);
    fputs("Line three: I love fishC.com!\n", fp);

    fclose(fp);


    if ((fp = fopen("lines.txt", "r")) == NULL)
    {
        printf("打开文件失败！\n");
        exit(EXIT_FAILURE);
    }

    while (!feof(fp))
    {
        if (fgets(buffer, 1024, fp))
            printf("%s\n", buffer);
    }
    fclose(fp);
    return 0;
}
