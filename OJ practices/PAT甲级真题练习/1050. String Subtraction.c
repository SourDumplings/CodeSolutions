/*
 @Date    : 2017-12-08 19:44:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1050
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 10001

int main()
{
    char S[MAX], D[MAX];
    gets(S);
    gets(D);
    int i;
    int asc[500];
    for (i = 0; i < 500; i++)
    {
        asc[i] = 0;
    }
    for (i = 0; S[i]; i++)
    {
        asc[(int)S[i]]++;
    }

    for (i = 0; D[i]; i++)
    {
        asc[(int)D[i]] = 0;
    }

    for (i = 0; S[i]; i++)
    {
        if (asc[(int)S[i]]-- > 0)
        {
            putchar(S[i]);
        }
    }
    putchar('\n');
    return 0;
}

