/*
 @Date    : 2018-04-17 19:46:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
判断读写文件的错误
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;

    if ((fp = fopen("output.txt", "r")) == NULL)
    {
        fputs("打开文件失败！\n", stderr);
        exit(EXIT_FAILURE);
    }

    int ch;
    while (1)
    {
        ch = fgetc(fp);
        if (feof(fp))
        {
            break;
        }
        putchar(ch);
    }

    fputc('c', fp);

    if (ferror(fp))
    {
        fputs("出错了！\n", stderr);
    }

    clearerr(fp);
    if (feof(fp) || ferror(fp))
    {
        printf("文件中还有错误！\n");
    }

    fclose(fp);
    return 0;
}
