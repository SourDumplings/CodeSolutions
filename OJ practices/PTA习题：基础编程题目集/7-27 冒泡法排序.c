#include <stdio.h>

int main()
{
    int N, K;
    int num[100], i, temp, j;

    scanf("%d %d", &N, &K);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }

    for (i = 0; i < K; i++)
    {
        for (j = 0; j < N - 1; j++)
        {
            if (num[j] >= num[j+1])
            {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }

    for (i = 0; i < N;i++)
    {
        printf("%d", num[i]);
        if(i != N-1)
        {
            putchar(' ');
        }
    }
    putchar('\n');


    return 0;
}
