#include <stdio.h>

#define MAXN 101

int output = 0; // 记录有没有过输出
int first = 1; // 标记是否是第一个输出

void Output(int coef, int expon)
{
    if (!first && coef > 0)
    {
        putchar('+');
    }
    if (coef == 1)
    {
        output = 1;
        switch (expon)
        {
            case 0 : printf("%d\n", coef); break;
            case 1 : printf("x"); break;
            default : printf("x%d", expon); break;
        }
    }
    else if (coef > 1 || coef < 0)
    {
        output = 1;
        switch (expon)
        {
            case 0 : printf("%d\n", coef); break;
            case 1 : printf("%dx", coef); break;
            default : printf("%dx%d", coef, expon); break;
        }
    }
    else if (coef == 0 && expon == 0 && output == 0)
    {
        printf("0\n");
    }
    return;
}

int main()
{
    int p1[MAXN] = {0}, p2[MAXN] = {0};
    int expon, coef;
    int flag = 0;
    int i;

    do
    {
        scanf("%d %d", &expon, &coef);
        if (!flag)
        {
            p1[expon] = coef;
        }
        else if (flag == 1)
        {
            p2[expon] = coef;
        }
        if (!expon)
        {
            flag++;
        }
    } while (flag != 2);

    for (i = MAXN - 1; i >= 0; i--)
    {
        Output(p1[i]+p2[i], i);
        if (output && first)
        {
            first = 0;
        }
    }
    return 0;
}
