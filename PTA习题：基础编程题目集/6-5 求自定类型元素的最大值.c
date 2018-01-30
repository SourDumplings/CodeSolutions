#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Max( ElementType S[], int N );

int main ()
{
    ElementType S[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &S[i]);
    printf("%.2f\n", Max(S, N));

    return 0;
}


ElementType Max( ElementType S[], int N )
{
    int i;
    ElementType max = S[0];

    for (i = 0; i < N; i++)
    {
        if (S[i] >= max)
        {
            max = S[i];
        }
    }

    return max;
}
