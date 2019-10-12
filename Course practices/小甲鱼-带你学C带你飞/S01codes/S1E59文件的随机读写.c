/*
 @Date    : 2018-04-16 21:05:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
文件的随机读写
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;

    if ((fp = fopen("Hello.txt", "w")) == NULL)
    {
        printf("文件打开失败！\n");
        exit(EXIT_FAILURE);
    }

    printf("%ld\n", ftell(fp));
    fputc('F', fp);
    printf("%ld\n", ftell(fp));
    fputs("ishC\n", fp);
    printf("%ld\n", ftell(fp));

    rewind(fp);
    fputs("Hello", fp);


    fclose(fp);
    return 0;
}
