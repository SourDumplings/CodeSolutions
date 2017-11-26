/*
 @Date    : 2017-11-22 09:46:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6477
 */

#include <stdio.h>

int cutoff = 3;

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int Median3(int A[], int left, int right)
{
    int center = (left+right)/2;
    if (A[left] > A[center])
    {
        Swap(&A[left], &A[center]);
    }
    if (A[center] > A[right])
    {
        Swap(&A[right], &A[center]);
    }
    if (A[center] < A[left])
    {
        Swap(&A[left], &A[center]);
    }
    Swap(&A[center], &A[right-1]);
    return A[right-1];
}

void Insert_Sort(int A[], int N)
{
    int i, j, temp;
    for (i = 1; i < N; i++)
    {
        temp = A[i];
        for (j = i; j > 0 && A[j-1] > temp; j--)
        {
            A[j] = A[j-1];
        }
        A[j] = temp;
    }
    return;
}

void Do_Quick_Sort(int A[], int left, int right)
{
    if (right - left >= cutoff)
    {
        int i, j;
        int pivot = Median3(A, left, right);
        i = left;
        j = right - 1;
        while (i < j)
        {
            while (A[++i] < pivot);
            while (A[--j] > pivot);
            if (i < j)
            {
                Swap(&A[i], &A[j]);
            }
        }
        Swap(&A[i], &A[right-1]);
        Do_Quick_Sort(A, left, i-1);
        Do_Quick_Sort(A, i+1, right);
    }
    else
    {
        int *p = A + left;
        Insert_Sort(p, right-left + 1);
    }
    return;
}

void Quick_Sort(int A[], int N)
{
    Do_Quick_Sort(A, 0, N-1);
    return;
}

int main()
{
    int N;
    scanf("%d", &N);
    int i;
    int A[N];
    int output = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    Quick_Sort(A, N);
    // Insert_Sort(A, N);
    for (i = 0; i < N; i++)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", A[i]);
    }
    putchar('\n');
    return 0;
}

