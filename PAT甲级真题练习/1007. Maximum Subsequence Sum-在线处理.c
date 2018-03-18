/*
 @Date    : 2017-11-27 19:28:31
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1007
 */

#include <stdio.h>

int first;
int last;

int MaxSubSum(int num[], int N)
{
    int i;
    int thissum = 0, maxsum = -1;
    int thisfirst = num[0];
    for (i = 0; i < N; i++)
    {
        thissum += num[i];
        if (thissum >= 0 && thissum > maxsum)
        {
            first = thisfirst;
            last = num[i];
            maxsum = thissum;
        }
        else if (thissum < 0)
        {
            thissum = 0;
            if (i < N - 1)
            {
                thisfirst = num[i + 1];
            }
        }
    }
    if (maxsum == -1)
    {
        maxsum = 0;
    }
    return maxsum;
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
    first = num[0];
    last = num[N-1];
    int maxsubsum;
    maxsubsum = MaxSubSum(num, N);
    printf("%d %d %d\n", maxsubsum, first, last);
    return 0;
}

