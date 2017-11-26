#include <stdio.h>

int MaxSubseqSum(int List[], int N)
{
    int i;
    int thissum, maxsum = 0;
    thissum = 0;

    for (i = 0; i < N; i++)
    {
        thissum += List[i];
        if (thissum > maxsum)
        {
            maxsum = thissum;
        }
        else if (thissum < 0)
        {
            thissum = 0;
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
