/*
 @Date    : 2018-04-17 19:52:36
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
显示错误原因
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    FILE *fp;

    // if ((fp = fopen("yagenjiubucunzaidewenjian.txt", "r")) == NULL)
    // {
    //     printf("打开文件失败！原因是：%d\n", errno);
            // exit(EXIT_FAILURE);
    // }


    // if ((fp = fopen("yagenjiubucunzaidewenjian.txt", "r")) == NULL)
    // {
    //     perror("打开文件失败！原因是");
    //     exit(EXIT_FAILURE);
    // }

    if ((fp = fopen("yagenjiubucunzaidewenjian.txt", "r")) == NULL)
    {
        fprintf(stderr, "打开文件失败！原因是 %s!纳尼！\n", strerror(errno));
        exit(EXIT_FAILURE);
    }
    fclose(fp);
    return 0;
}
