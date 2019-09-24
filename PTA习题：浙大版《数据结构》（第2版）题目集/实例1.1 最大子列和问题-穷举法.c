#include <stdio.h>

int MaxSubseqSum(int List[], int N)
{
    int i, j, k;
    int thissum, maxsum = 0;
    for (i = 0; i < N; i++)
    {
        for (j = i; j < N; j++)
        {
            thissum = 0;
            for (k = i; k <= j; k++)
            {
                thissum += List[k];
            }
            if (thissum > maxsum)
            {
                maxsum = thissum;
            }
        }
    }
    return maxsum;
}

int main()
{
    int N;
    scanf("%d", &N);
    int List[N];
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &List[i]);
    }
    printf("%d\n", MaxSubseqSum(List, N));
    return 0;
}
