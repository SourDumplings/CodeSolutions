#include <stdio.h>


void Maxsum(int num[], int K)
{
    int i, maxsum = 0, thissum = 0;
    int maxstart = num[0], maxend = num[K - 1];
    int thisstart = num[0], thisend = num[0];
    int flag = 0, first = 1; // flag = 0代表还没有遇到第一个非负元素，first = 1代表还没有针对第一个非负元素进行调整

    for (i = 0; i < K; i++)
    {
        if (num[i] >= 0 && first == 1)
        {
            flag = 1;
        }
        thissum += num[i];
        thisend = num[i];
        if (flag)
        {
            maxstart = thisstart;
            maxend = thisend;
            first = 0;
            flag = 0;
        }
        if (thissum > maxsum)
        {
            maxstart = thisstart;
            maxend = thisend;
            maxsum = thissum;
        }
        else if (thissum < 0)
        {
            thissum = 0;
            thisstart = num[i+1];
        }
    }

    printf("%d %d %d\n", maxsum, maxstart, maxend);

    return;
}

int main()
{
    int K;
    int num[10000];
    int i;

    scanf("%d", &K);

    for (i = 0; i < K; i++)
    {
        scanf("%d", &num[i]);
    }

    Maxsum(num, K);

    return 0;
}
