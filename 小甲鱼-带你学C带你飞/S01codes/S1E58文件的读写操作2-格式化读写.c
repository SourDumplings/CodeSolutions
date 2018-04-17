/*
 @Date    : 2018-04-16 20:04:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
文件的格式化读写操作
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    FILE *fp;
    struct tm *p;
    time_t t;

    time(&t);
    p = localtime(&t);

    if ((fp = fopen("date.txt", "w")) == NULL)
    {
        printf("打开文件失败！\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "%d-%d-%d\n", 1900 + p->tm_year, 1 + p->tm_mon, p->tm_mday);
    fclose(fp);

    int year, month, day;

    if ((fp = fopen("date.txt", "r")) == NULL)
    {
        printf("打开文件失败！\n");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d-%d-%d\n", &year, &month, &day);
    printf("%d-%d-%d\n", year, month, day);

    fclose(fp);

    return 0;
}
