#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char num[9999];
    gets(num);
    int i;
    int l = strlen(num);
    int eff[9999] = {0}, index[4];
    int l_e = 0, l_i = 0;
    int flag = 0; // 记录是否读到了指数
    int pos = 1; // 记录指数的正负
    int expon = 0;
    int j;
    int r_zero = 0;

    if (num[0] == '-')
    {
        printf("-");
    }
    for (i = 1; i < l; i++)
    {
        if (num[i] == 'E')
        {
            flag = 1;
            continue;
        }
        if (!flag)
        {
            if (num[i] == '.')
            {
                eff[l_e++] = num[i];
                continue;
            }
            eff[l_e++] = num[i] - '0';
        }
        else
        {
            if (num[i] == '-')
            {
                pos = 0;
                continue;
            }
            else if (num[i] == '+')
            {
                continue;
            }
            else
            {
                index[l_i++] = num[i] - '0';
            }
        }
    }

    for (i = 0; i < l_i; i++)
    {
        expon += index[i] * pow(10, l_i-i-1);
    }

    if (!pos)
    {
        printf("0.");
        for (i = 0; i < expon - 1; i++)
        {
            printf("0");
        }
        for (i = 0; i < l_e; i++)
        {
            if (eff[i] != '.')
            {
                printf("%d", eff[i]);
            }
        }
    }
    else
    {
        // 打印第一个整数位
        printf("%d", eff[0]);
        // 打印.后的有效数字直到该输出小数点
        for (i = 2; i <= l_e - 1; i++)
        {
            printf("%d", eff[i]);
        }
        // 判断是否有小数部分，有的话打印小数点
        if (l_e - 2 > expon)
        {
            printf(".");
        }
        // 打印剩余有效数字
        for (j = i; j < l_e; j++)
        {
            printf("%d", eff[j]);
        }
        // 打印较大的指数导致末尾许多的零
        if (l_e - 2 < expon)
        {
            r_zero = expon - l_e + 2;
            for (i = 0; i < r_zero; i++)
            {
                printf("0");
            }
        }
    }
    putchar('\n');


    return 0;
}
