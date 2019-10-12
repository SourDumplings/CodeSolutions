/*
 * @Autor: SourDumplings
 * @Date: 2019-09-27 18:54:29
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://pintia.cn/problem-sets/15/problems/720
 */

#include <cstdio>

int partition(int A[], int lo, int hi)
{
    int pivot = A[lo];
    while (lo < hi)
    {
        while (lo < hi && pivot <= A[hi])
        {
            --hi;
        }
        A[lo] = A[hi];
        while (lo < hi && A[lo] <= pivot)
        {
            ++lo;
        }
        A[hi] = A[lo];
    }
    A[lo] = pivot;
    return lo;
}

void quick_sort(int A[], int lo, int hi)
{
    if (hi - lo < 1)
    {
        return;
    }

    int pos = partition(A, lo, hi);
    quick_sort(A, lo, pos - 1);
    quick_sort(A, pos + 1, hi);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    quick_sort(A, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
        {
            putchar(' ');
        }
        printf("%d", A[i]);
    }

    return 0;
}
