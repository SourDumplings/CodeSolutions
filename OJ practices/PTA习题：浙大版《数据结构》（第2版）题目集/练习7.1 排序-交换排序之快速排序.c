#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void DoQuickSort(int num[], int left, int right)
{
    int i = left, j = right;
    int key = num[(right+left)/2];
    while (i <= j)
    {
        for (; num[i] < key; i++);
        for (; num[j] > key; j--);
        if (i <= j)
        {
            Swap(&num[i], &num[j]);
            i++;
            j--;
        }
    }
    if (i < right)
    {
        DoQuickSort(num, i, right);
    }
    if (j > left)
    {
        DoQuickSort(num, left, j);
    }
    return;
}

void Quick_Sort(int num[], int N)
{
    // 统一接口
    DoQuickSort(num, 0, N-1);
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
    Quick_Sort(num, N);
    for (i = 0; i < N - 1; i++)
    {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[i]);
    return 0;
}
