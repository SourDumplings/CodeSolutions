#include <stdio.h>

int B = 51; // 需要的桶的个数

int main()
{
    int N;
    scanf("%d", &N);
    int i;
    int count[B];
    int temp;
    for (i = 0; i < B; i++)
    {
        count[i] = 0;
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        count[temp]++;
    }
    for (i = 0; i < B; i++)
    {
        if (count[i])
        {
            printf("%d:%d\n", i, count[i]);
        }
    }
    return 0;
}
