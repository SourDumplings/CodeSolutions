#include <stdio.h>

int IsPerfectNum(int num)
{
    int i;
    int sum = 0;
    for (i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    if (sum == num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int i;
    int flag = 0; // 记录是否有完数
    for (i = n; i <= m; i++)
    {
        if (IsPerfectNum(i))
        {
            if (flag)
            {
                putchar(' ');
            }
            printf("%d", i);
            flag = 1;
        }
    }
    if (!flag)
    {
        printf("NIL");
    }
    putchar('\n');
    return 0;
}
