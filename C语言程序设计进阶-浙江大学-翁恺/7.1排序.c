/*
 @Date    : 2017-12-13 19:39:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
http://www.icourse163.org/learn/ZJU-200001?tid=1002316004#/learn/ojhw?id=1002886204
 */

#include <stdio.h>
#include <stdlib.h>

void do_quick_sort(int A[], int left, int right)
{
    int i = left, j = right;
    int pivot = A[(left+right)/2];
    int temp;
    while (i <= j)
    {
        for (; A[i] < pivot; i++);
        for (; A[j] > pivot; j--);
        if (i <= j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
            j--;
        }
    }
    if (i < right)
    {
        do_quick_sort(A, i, right);
    }
    if (j > left)
    {
        do_quick_sort(A, left, j);
    }
    return;
}

void quick_sort(int A[], int n)
{
    do_quick_sort(A, 0, n-1);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int A[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    quick_sort(A, n);
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    return 0;
}

