# include <stdio.h>

int MaxSubseqSum(int List[], int N);

int main()
{
    int N, i, MaxSum;

    scanf("%d", &N);
    getchar();
    int List[N];

    for (i = 0; i < N; i++)
    {
        scanf("%d", &List[i]);
        getchar();
    }

//    for (i = 0; i < N; i++)
//    {
//        printf("%d", List[i]);
//    }

    MaxSum = MaxSubseqSum(List, N);

    printf("%d", MaxSum);

    return 0;
}


int MaxSubseqSum(int List[], int N)
{
    int i;
    int ThisSum, MaxSum;

    ThisSum = MaxSum = 0;
    for (i = 0; i < N; i++)
    {
        ThisSum += List[i];
        if (ThisSum > MaxSum)
        {
            MaxSum = ThisSum;
        }
        else if (ThisSum < 0)
            ThisSum = 0;
    }

    return MaxSum;
}
