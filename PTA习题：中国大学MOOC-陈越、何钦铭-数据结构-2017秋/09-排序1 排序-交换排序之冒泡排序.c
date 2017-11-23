#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void Bubble_Sort(int num[], int N)
{
    int p, i, flag;
    for (p = N - 1; p >= 0; p--)
    {
        flag = 0;
        for (i = 0; i < p; i++)
        {
            if (num[i] > num[i+1])
            {
                Swap(&num[i], &num[i+1]);
                flag = 1;
            }
        }
        if (!flag)
        {
            break;
        }
    }
    return;
}

int main()
{
    int N;
    scanf("%d", &N);
    int num[N];
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }
    Bubble_Sort(num, N);
    for (i = 0; i < N - 1; i++)
    {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[i]);
    return 0;
}
