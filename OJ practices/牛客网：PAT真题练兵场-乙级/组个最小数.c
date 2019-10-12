#include <stdio.h>

void MakeMinNum(int n[])
{
    int j, k;
    for (j = 0; j < 10; j++)
    {
        for (k = 0; k < n[j]; k++)
        {
            printf("%d", j);
        }
    }
    return;
}

int main()
{
    int n[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &n[i]);
    }
    for (i = 1; i < 10; i++)
    {
        if (n[i])
        {
            printf("%d", i);
            n[i]--;
            MakeMinNum(n);
            putchar('\n');
            return 0;
        }
    }
    return 0;
}
