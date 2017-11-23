#include <stdio.h>

int cutoff = 3; // 当序列元素个数小于3时不用快排而用插入排序

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int Median3(int num[], int left, int right)
{
    int center = (left + right) / 2;
    if (num[center] < num[left])
    {
        Swap(&num[center], &num[left]);
    }
    if (num[center] > num[right])
    {
        Swap(&num[center], &num[right]);
    }
    if (num[center] < num[left])
    {
        Swap(&num[center], &num[left]);
    }
    Swap(&num[center], &num[right-1]);
    return num[right - 1];
}

void Insertion_Sort(int num[], int N)
{
    int i, j;
    int temp;
    for (i = 1; i < N; i++)
    {
        temp = num[i];
        for (j = i; j > 0 && num[j-1] > temp; j--)
        {
            num[j] = num[j-1];
        }
        num[j] = temp;
    }
    return;
}

void DoQuickSort(int num[], int left, int right)
{
    if (right - left >= cutoff - 1)
    {
        int i = left, j = right - 1;
        int pivot = Median3(num, left, right);
        while (i < j)
        {
            while (num[++i] < pivot);
            while (num[--j] > pivot);
            if (i < j)
            {
                Swap(&num[i], &num[j]);
            }
        }
        Swap(&num[i], &num[right-1]);
        DoQuickSort(num, left, i-1);
        DoQuickSort(num, i+1, right);
    }
    else
    {
        int *p = num + left;
        Insertion_Sort(p, right - left + 1);
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
