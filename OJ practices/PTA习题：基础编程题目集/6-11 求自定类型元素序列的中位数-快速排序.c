#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

void sort(ElementType A[], int left, int right)
{
    ElementType key = A[(right+left)/2], temp;
    int i = left, j = right;

    while (i <= j)
    {
        for (; A[i] < key; i++);
        for (; A[j] > key; j--);

        if (i <= j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;

            i++;
            j--;
        }
    }

    if (left < j)
    {
        sort(A, left, j);
    }
    if(i < right)
    {
        sort(A, i, right);
    }

    return;
}

ElementType Median( ElementType A[], int N )
{
    int i, j;
    ElementType m, temp;

    // 快速排序
    sort(A, 0, N-1);

    return A[N/2];
}
