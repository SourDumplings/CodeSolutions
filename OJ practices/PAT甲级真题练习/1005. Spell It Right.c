/*
 @Date    : 2017-11-27 13:36:28
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1005
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int sum = 0;
    int d;
    char s[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int spell[1000];
    int i = 0, j;
    while (c != '\n')
    {
        scanf("%c", &c);
        sum += atoi(&c);
    }
    if (!sum)
    {
        printf("zero\n");
    }
    else
    {
        while (sum)
        {
            d = sum % 10;
            spell[i++] = d;
            sum /= 10;
        }
        int output = 0;
        for (j = i - 1; j >= 0; j--)
        {
            if (output++)
            {
                putchar(' ');
            }
            printf("%s", s[spell[j]]);
        }
        printf("\n");
    }
    return 0;
}

