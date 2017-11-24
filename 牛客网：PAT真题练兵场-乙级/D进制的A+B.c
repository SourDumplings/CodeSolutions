#include <stdio.h>

int main()
{
    int A, B, D;
    scanf("%d %d %d", &A, &B, &D);
    int result[32] = {0};
    int sum;
    int i;
    int flag = 0;
    sum = A + B;
    for (i = 0; sum; i++)
    {
        result[i] = sum % D;
        sum /= D;
    }
    for (i = 31; i >= 0; i--)
    {
        if (!flag && result[i])
        {
            flag = 1;
        }
        if (flag)
        {
            printf("%d", result[i]);
        }
    }
    putchar('\n');
    return 0;
}
