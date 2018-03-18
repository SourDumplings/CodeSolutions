/*
 @Date    : 2017-11-28 09:39:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1008
 */

#include <stdio.h>

int main()
{
    int N;
    scanf("%d", &N);
    int i, this_f = 0, next, totaltime = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &next);
        if (next > this_f)
        {
            totaltime += (next - this_f) * 6;
        }
        else if (next < this_f)
        {
            totaltime += (this_f - next) * 4;
        }
        totaltime += 5;
        this_f = next;
    }
    printf("%d\n", totaltime);
    return 0;
}
