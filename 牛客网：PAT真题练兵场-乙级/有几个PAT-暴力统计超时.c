/*
 @Date    : 2017-11-23 21:22:13
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.nowcoder.com/pat/6/problem/4066
 */

#include <stdio.h>

#define MAX 100000

int main()
{
    char s[MAX+1];
    gets(s);
    int i, j, k;
    int count = 0;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == 'P')
        {
            for (j = i + 1; s[j]; j++)
            {
                if (s[j] == 'A')
                {
                    for (k = j + 1; s[k]; k++)
                    {
                        if (s[k] == 'T')
                        {
                            count = (count + 1) % 1000000007;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n", count);
    return 0;
}

