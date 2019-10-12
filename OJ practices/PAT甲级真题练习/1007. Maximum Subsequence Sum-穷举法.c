/*
 @Date    : 2017-11-27 20:27:39
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/submissions/3830263
 */

#include <stdio.h>

int first;
int last;

int MaxSubSum(int num[], int N)
{
    int i, j;
    int thissum = 0, maxsum = -1;
    int thisfirst;
    for (i = 0; i < N; i++)
    {
        thisfirst = num[i];
        thissum = 0;
        for (j = i; j < N; j++)
        {
            thissum += num[j];
            if (thissum >= 0 && thissum > maxsum)
            {
                last = num[j];
                maxsum = thissum;
                first = thisfirst;
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

