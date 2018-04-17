/*
 @Date    : 2018-04-17 19:42:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
当文件打开错误时错误信息打印到标准错误输出流
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    FILE *fp;

    if ((fp = fopen("yagenjiubucunzaidewenjian.txt", "r")) == NULL)
    {
        fputs("打开文件失败！\n", stderr);
        exit(EXIT_FAILURE);
    }

    fclose(fp);
    return 0;
}
