#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int ScanforMin(int num[], int start, int end)
{
    int i, minposition = start;
    for (i = start; i <= end; i++)
    {
        if (num[i] < num[minposition])
        {
            minposition = i;
        }
    }
    return minposition;
}

void Selection_Sort(int num[], int N)
{
    int i, minposition;
    for (i = 0; i < N - 1; i++)
    {
        minposition = ScanforMin(num, i, N - 1);
        Swap(&num[i], &num[minposition]);
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
    Selection_Sort(num, N);
    for (i = 0; i < N - 1; i++)
    {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[i]);
    return 0;
}
