/*
 @Date    : 2017-11-26 16:52:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1001
 */

#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int sum = a + b;
    int i = 0;
    char c;
    if (sum < 0)
    {
        putchar('-');
        sum *= -1;
    }
    char result[10];
    int count_num = 0;
    if (sum == 0)
    {
        result[i++] = '0';
    }
    else
    {
        while (sum)
        {
            c = sum % 10 + 48;
            result[i++] = c;
            count_num++;
            sum /= 10;
            if (count_num % 3 == 0)
            {
                result[i++] = ',';
            }
        }
    }
    int j;
    for (j = i - 1; j >= 0; j--)
    {
        if (j == i - 1 && result[j] == ',')
        {
            continue;
        }
        printf("%c", result[j]);
    }
    putchar('\n');
    return 0;
}

