#include <stdio.h>

int n;

int FindRowMax(int onerow[])
{
    int i, max = onerow[0], max_i = 0;
    for (i = 1; i < n; i++)
    {
        if (onerow[i] > max)
        {
            max = onerow[i];
            max_i = i;
        }
    }
    return max_i;
}

int FindColMin(int num[][n], int column)
{
    int r;
    int min = num[0][column];
    for (r = 0; r < n; r++)
    {
        if (num[r][column] < min)
        {
            min = num[r][column];
        }
    }
    return min;
}

int main()
{
    scanf("%d", &n);
    int i, j;
    int num[n][n];
    int output = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &num[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        int column;
        column = FindRowMax(num[i]);
        if (num[i][column] == FindColMin(num, column))
        {
            printf("%d %d\n", i, column);
            output = 1;
            break;
        }
    }
    if (!output)
    {
        printf("NO\n");
    }
    return 0;
}
