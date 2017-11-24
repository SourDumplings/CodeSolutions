/*
 @Date    : 2017-11-14 13:32:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.nowcoder.com/pat/6/problem/4059
 */

#include <stdio.h>
#include <ctype.h>

#define MAX 100001

int flag = 0; // 记录上档键有没有坏


int IsBroken(char broken[], char c)
{
    int i;
    for (i = 0; broken[i] != '\0'; i++)
    {
        if (c == broken[i] ||
            c == tolower(broken[i]) ||
            (flag && isupper(c)))
            {
                return 1;
            }
    }
    return 0;
}

int main()
{
    char broken[MAX];
    gets(broken);
    char A[MAX];
    gets(A);
    int i;
    for (i = 0; broken[i] != '\0'; i++)
    {
        if (broken[i] == '+')
        {
            flag = 1;
            break;
        }
    }
    char result[MAX];
    int r = 0;
    for (i = 0; A[i] != '\0'; i++)
    {
        if (!IsBroken(broken, A[i]))
        {
            result[r++] = A[i];
        }
    }
    puts(result);
    return 0;
}

