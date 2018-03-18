/*
 @Date    : 2017-12-07 09:07:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1043
 */

#include <stdio.h>
#include <stdlib.h>

int pre[1000], post[1000];

int Judge(int s, int e, int ps, int pe)
{
    if (e <= s)
    {
        if (e == s)
        {
            post[pe] = pre[s];
        }
        return 1;
    }
    else
    {
        post[pe] = pre[s];
        int i, rr = s;
        int flag = 1;
        for (i = s+1; i <= e; i++)
        {
            if (pre[i] >= pre[s])
            {
                rr = i;
                break;
            }
        }
        if (rr > s)
        {
            for (i = rr+1; i <= e; i++)
            {
                if (pre[i] < pre[s])
                {
                    // printf("$$In Judge, pre[%d] = %d in right tree is smaller than the root pre[%d] = %d.$$\n", i, pre[i], s, pre[s]);
                    flag = 0;
                    break;
                }
            }
            return flag && Judge(s+1, rr-1, ps, ps+(rr-s-1)-1) && Judge(rr, e, pe-(e-rr+1), pe-1);
        }
        else
        {
            // 没有右子树
            return Judge(rr+1, e, ps, pe-1);
        }
    }
}

int JudgeMirror(int s, int e, int ps, int pe)
{
    if (e <= s)
    {
        if (e == s)
        {
            post[pe] = pre[s];
        }
        return 1;
    }
    else
    {
        post[pe] = pre[s];
        int i, rr = s;
        int flag = 1;
        for (i = s+1; i <= e; i++)
        {
            if (pre[i] < pre[s])
            {
                rr = i;
                break;
            }
        }
        if (rr > s)
        {
            for (i = rr+1; i <= e; i++)
            {
                if (pre[i] >= pre[s])
                {
                    // printf("$$In JudgeMirror, pre[%d] = %d in right tree is greater than the root pre[%d] = %d.$$\n", i, pre[i], s, pre[s]);
                    flag = 0;
                    break;
                }
            }
            return flag && JudgeMirror(s+1, rr-1, ps, ps+(rr-s-1)-1) && JudgeMirror(rr, e, pe-(e-rr+1), pe-1);
        }
        else
        {
            return JudgeMirror(rr+1, e, ps, pe-1);
        }
    }
}

int main()
{
    int N;
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++)
    {
        scanf("%d", &pre[i]);
    }
    int flag;
    flag = Judge(0, N-1, 0, N-1);
    if (!flag)
    {
        flag = JudgeMirror(0, N-1, 0, N-1);
    }

    int output = 0;
    if (flag)
    {
        printf("YES\n");
        for (i = 0; i < N; i++)
        {
            if (output++)
            {
                putchar(' ');
            }
            printf("%d", post[i]);
        }
        putchar('\n');
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

