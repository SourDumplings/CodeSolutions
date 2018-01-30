#include <stdio.h>

void PrintResult(float a, float b)
{
    int judge_a, judge_b;
    judge_a = (int)(a / 0.1);
    judge_b = (int)(b / 0.1);

    if (!judge_a && !judge_b)
    {
        printf("0.0\n");
        return;
    }
    if (judge_a)
    {
        printf("%.1f", a);
    }

    if (judge_b)
    {
        if (b > 0)
        {
            if (judge_a)
            {
                printf("+");
            }
            printf("%.1fi", b);
        }
        else if(b < 0)
        {
            printf("%.1fi", b);
        }
    }
    putchar('\n');
    return;
}

void PrintForm(float a1, float b1, float a2, float b2, char c)
{
    putchar('(');
    if (!a1 && !b1)
    {
        printf("0.0");
    }
    else
    {
        printf("%.1f", a1);

        if (b1 >= 0)
        {
            printf("+%.1fi", b1);
        }
        else if (b1 < 0)
        {
            printf("%.1fi", b1);
        }
    }
    putchar(')');

    printf(" %c ", c);

        putchar('(');
    if (!a2 && !b2)
    {
        printf("0.0");
    }
    else
    {
        printf("%.1f", a2);

        if (b2 >= 0)
        {
            printf("+%.1fi", b2);
        }
        else if (b2 < 0)
        {
            printf("%.1fi", b2);
        }
    }
    putchar(')');

    printf(" = ");
    return;
}

int main()
{
    float a1, b1, a2, b2;
    float a, b;

    scanf("%f %f %f %f", &a1, &b1, &a2, &b2);

    // sum
    a = a1 + a2;
    b = b1 + b2;
    PrintForm(a1, b1, a2, b2, '+');
    PrintResult(a, b);

    // substract
    a = a1 - a2;
    b = b1 - b2;
    PrintForm(a1, b1, a2, b2, '-');
    PrintResult(a, b);

    // multiple
    a = a1 * a2 - b1 * b2;
    b = a1 * b2 + a2 * b1;
    PrintForm(a1, b1, a2, b2, '*');
    PrintResult(a, b);

    // devide
    a = (a1 * a2 + b1 * b2) / (a2 * a2 + b2 * b2);
    b = (b1 * a2 - a1 * b2) / (a2 * a2 + b2 * b2);
    PrintForm(a1, b1, a2, b2, '/');
    PrintResult(a, b);

    return 0;
}
