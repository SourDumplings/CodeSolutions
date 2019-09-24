#include <stdio.h>

void Insert_Sort(int num[], int N)
{
    int p, i;
    int temp;
    for (p = 1; p < N; p++)
    {
        temp = num[p];
        for (i = p; i > 0 && num[i-1] > temp; i--)
        {
            num[i] = num[i-1];
        }
        num[i] = temp;
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
    Insert_Sort(num, N);
    for (i = 0; i < N - 1; i++)
    {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[i]);
    return 0;
}
