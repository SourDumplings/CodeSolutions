/*
 @Date    : 2017-11-18 13:12:31
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6180
 */

#include <stdio.h>

void FindAncestor(int T[], int i1, int i2)
{
    if (!T[i1])
    {
        printf("ERROR: T[%d] is NULL\n", i1);
    }
    else if (!T[i1])
    {
        printf("ERROR: T[%d] is NULL\n", i2);
    }
    else
    {
        int a1, a2, flag = 0;
        for (a1 = i1; a1 > 0; a1 /= 2)
        {
            for (a2 = i2; a2 > 0; a2 /= 2)
            {
                if (a2 == a1)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        }
        printf("%d %d\n", a2, T[a2]);
    }
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int T[n+1];
    int i;
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &T[i]);
    }
    int i1, i2;
    scanf("%d %d", &i1, &i2);
    FindAncestor(T, i1, i2);
    return 0;
}

