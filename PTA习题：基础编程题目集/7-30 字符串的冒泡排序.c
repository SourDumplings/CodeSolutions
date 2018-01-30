#include <stdio.h>
#include <string.h>

int main()
{
    char str[100][11];
    int k, n0, n, i;
    char temp[11];

    scanf("%d %d\n", &n, &k); // 要输入一个回车，不然 gets 会得到一个回车，转为\0 存入第一个字符串中

    n0 = n;

    for (i = 0; i < n; i++)
    {
        gets(str[i]);
    }

    for (; k; k--)
    {
        n -= 1;
        for (i = 0; i < n; i++)
        {
            if (strcmp(str[i], str[i+1]) > 0)
            {
                strcpy(temp, str[i]);
                strcpy(str[i], str[i+1]);
                strcpy(str[i+1], temp);
            }
        }
    }

    for (i = 0; i < n0; i++)
    {
        puts(str[i]);
    }

    return 0;
}
