#include <stdio.h>
#include <stdlib.h>

void Merge(int num[], int tempnum[], int L, int R, int RightEnd)
{
    int LeftEnd = R - 1;
    int temp = L;
    int numelements = RightEnd - L + 1;
    int i;
    while (L <= LeftEnd && R <= RightEnd)
    {
        if (num[L] <= num[R])
        {
            tempnum[temp++] = num[L++];
        }
        else
        {
            tempnum[temp++] = num[R++];
        }
    }
    while (L <= LeftEnd)
    {
        tempnum[temp++] = num[L++];
    }
    while (R <= RightEnd)
    {
        tempnum[temp++] = num[R++];
    }
    for (i = 0; i < numelements; i++, RightEnd--)
    {
        num[RightEnd] = tempnum[RightEnd];
    }
    return;
}

void MSort(int num[], int tempnum[], int L, int RightEnd)
{
    int center;
    if (L < RightEnd)
    {
        center = (L + RightEnd) / 2;
        MSort(num, tempnum, L, center);
        MSort(num, tempnum, center+1, RightEnd);
        Merge(num, tempnum, L, center+1, RightEnd);
    }
    return;
}

void Merge_Sort(int num[], int N)
{
    int *tempnum;
    tempnum = (int *)malloc(N*sizeof(int));
    if (tempnum)
    {
        MSort(num, tempnum, 0, N-1);
    }
    return;
}

int main()
{
    int N;
    scanf("%d", &N);
    int num[N];
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }
    Merge_Sort(num, N);
    for (i = 0; i < N - 1; i++)
    {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[i]);
    return 0;
}
