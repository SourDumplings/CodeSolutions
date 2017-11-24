#include <stdio.h>

void QuickSort(int num[], int left, int right)
{
    int i = left, j = right;
    int temp;
    int key = num[(left+right)/2];

    while (i <= j)
    {
        for (; num[i] < key; i++);
        for (; num[j] > key; j--);
        if (i <= j)
        {
            temp = num[i];
            num[i] = num[j];
            num[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
    {
        QuickSort(num, left, j);
    }
    if (i < right)
    {
        QuickSort(num, i, right);
    }
    return;
}

void ReverseQuickSort(int num[], int left, int right)
{
    int i = left, j = right;
    int temp;
    int key = num[(left+right)/2];

    while (i <= j)
    {
        for (; num[i] > key; i++);
        for (; num[j] < key; j--);
        if (i <= j)
        {
            temp = num[i];
            num[i] = num[j];
            num[j] = temp;
            i++;
            j--;
        }
    }

    if (left < j)
    {
        ReverseQuickSort(num, left, j);
    }
    if (i < right)
    {
        ReverseQuickSort(num, i, right);
    }
    return;
}

int IsSame(int num[])
{
    int i, key = num[0];
    for (i = 1; i < 4; i++)
    {
        if (num[i] != key)
        {
            return 0;
        }
    }
    return 1;
}

int OutPut(int num[], int n)
{
    int i;
    int n1 = 0, n2 = 0;
    QuickSort(num, 0, 3);
    for (i = 3; i >= 0; i--)
    {
        n1 = n1 * 10 + num[i];
    }
    ReverseQuickSort(num, 0, 3);
    for (i = 3; i >= 0; i--)
    {
        n2 = n2 * 10 + num[i];
    }
    int result = n1 - n2;
    printf("%04d - %04d = %04d\n", n1, n2, result);
    if (IsSame(num))
    {
        return -1;
    }
    for (i = 0; i < 4; i++)
    {
        num[i] = result % 10;
        result /= 10;
    }
    return n1 - n2;
}

int main()
{
    int n;
    int i;
    scanf("%d", &n);
    int num[4];
    for (i = 0; i < 4; i++)
    {
        num[i] = n % 10;
        n /= 10;
    }

    while (n != 6174)
    {
        if (n == -1)
        {
            return 0;
        }
        n = OutPut(num, n);
    }

    return 0;
}
