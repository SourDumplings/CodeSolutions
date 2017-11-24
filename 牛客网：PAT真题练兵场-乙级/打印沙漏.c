#include <stdio.h>

int main()
{
    int n;
    char c;
    scanf("%d %c", &n, &c);
    int i, j, k;
    int sum = 0;
    int flag;
    int n_blank;
    int count_blank;
    int count_c;

    // 计算总共打印的符号数
    for (i = 0; i <= n; i++)
    {
        if (i == 0)
        {
            sum += 1;
        }
        else
        {
            if (sum + 2 * (2 * i + 1) <= n)
            {
                sum += 2 * (2 * i + 1);
            }
            else
            {
                i -= 1;
                break;
            }
        }
    }

    // 打印沙漏
    for (j = i; j >= 0; j--)
    {
        n_blank = i - j;
        count_blank = 0;
        count_c = 0;
        flag = 0;
        for (k = 0; k < 2 * i + 1; k++)
        {
            if (!flag && n_blank)
            {
                printf(" ");
                count_blank++;
                if (count_blank == n_blank)
                {
                    flag = 1;
                    count_blank = 0;
                }
            }
            else
            {
                printf("%c", c);
                count_c++;
                if (count_c == 2 * j + 1)
                {
                    break;
                }
            }
        }
        printf("\n");
    }
    for (j = 1; j <= i; j++)
    {
        n_blank = i - j;
        count_blank = 0;
        count_c = 0;
        flag = 0;
        for (k = 0; k < 2 * i + 1; k++)
        {
            if (!flag && n_blank)
            {
                printf(" ");
                count_blank++;
                if (count_blank == n_blank)
                {
                    flag = 1;
                    count_blank = 0;
                }
            }
            else
            {
                printf("%c", c);
                count_c++;
                if (count_c == 2 * j + 1)
                {
                    break;
                }
            }
        }
        printf("\n");
    }
    printf("%d\n", n - sum);
    return 0;
}
