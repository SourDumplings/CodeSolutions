#include <stdio.h>

int MaxSubseqSum(int List[], int N)
{
    int i, j;
    int thissum, maxsum = 0;
    for (i = 0; i < N; i++)
    {
        thissum = 0;
        for (j = i; j < N; j++)
        {
            thissum += List[j];
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
