/*
 @Date    : 2017-11-23 21:29:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.nowcoder.com/pat/6/problem/4066
思路来自：https://www.liuchuo.net/archives/573
将每个A前的P的个数（取模）和之后的T的个数（取模）相乘再累加就得到结果了
 */

#include <stdio.h>

#define MAX 100000
#define LIM 1000000007

int main()
{
    char s[MAX+1];
    gets(s);
    int countap, countat;
    int i, j;
    countat = countap = 0;
    int result = 0;
    int firsta = 1;
    for (i = 0; s[i]; i++)
    {
        if (s[i] == 'P')
        {
            countap++;
        }
        else if (s[i] == 'A')
        {
            if (firsta)
            {
                firsta = 0;
                for (j = i + 1; s[j]; j++)
                {
                    if (s[j] == 'T')
                    {
                        countat++;
                    }
                }
            }
            result = (result + (countap % LIM) * (countat % LIM)) % LIM;
        }
        else if (!firsta && s[i] == 'T')
        {
            countat--;
        }
    }

    printf("%d\n", result);

    return 0;
}

