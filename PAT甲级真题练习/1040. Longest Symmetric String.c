/*
 @Date    : 2017-12-06 19:45:37
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1040
要分奇偶两种情况讨论
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GetOddLength(char s[], int center, int l)
{
    int i;
    int thislength = 3;
    for (i = 2; center - i >= 0; i++)
    {
        if (s[center-i] == s[center+i])
        {
            thislength += 2;
        }
        else
        {
            break;
        }
    }
    return thislength;
}

int GetEvenLength(char s[], int left, int right, int l)
{
    int thislength = 2;
    int i;
    for (i = 1; left - i >= 0 && right + i < l; i++)
    {
        if (s[left-i] == s[right+i])
        {
            thislength += 2;
        }
        else
        {
            break;
        }
    }
    return thislength;
}

int main()
{
    char s[1001];
    gets(s);
    int i;
    int l = strlen(s);
    int thislength = 1, maxlength = 1;
    for (i = 1; i < l - 1; i++)
    {
        if (s[i-1] == s[i+1])
        {
            thislength = GetOddLength(s, i, l);
            if (thislength > maxlength)
            {
                maxlength = thislength;
            }
        }
    }
    for (i = 0; i < l - 1; i++)
    {
        if (s[i] == s[i+1])
        {
            thislength = GetEvenLength(s, i, i+1, l);
            if (thislength > maxlength)
            {
                maxlength = thislength;
            }
        }
    }
    printf("%d\n", maxlength);
    return 0;
}

