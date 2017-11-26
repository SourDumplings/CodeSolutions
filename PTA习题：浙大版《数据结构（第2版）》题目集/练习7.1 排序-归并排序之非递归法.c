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

void Merge_pass(int num[], int tempnum[], int N, int length)
{
    int i, j;
    for (i = 0; i <= N - 2 * length; i += 2 * length)
    {
        Merge(num, tempnum, i, i+length, i+2*length-1);
    }
    if (i + length < N)
    {
        Merge(num, tempnum, i, i+length, N-1);
    }
    else
    {
        for (j = i; j < N; j++)
        {
            tempnum[j] = num[j];
        }
    }
    return;
}

void Merge_Sort(int num[], int N)
{
    int *tempnum;
    int length = 1;
    tempnum = (int *)malloc(N*sizeof(int));
    if (tempnum)
    {
        while (length < N)
        {
            Merge_pass(num, tempnum, N, length);
            length *= 2;
            Merge_pass(tempnum, num, N, length);
            length *= 2;
        }
        free(tempnum);
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
