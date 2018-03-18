/*
 @Date    : 2017-12-07 19:18:08
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1044
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100000
#define INFINITY 999999999
#define max(a, b) ((a) > (b) ? (a) : (b))

typedef struct PAIR *Pair;
struct PAIR
{
    int i, j;
};

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    int chain[MAXN];
    int i, j;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &chain[i]);
    }

    int thissum = 0;
    int minoversum = INFINITY;
    Pair result[MAXN];
    Pair overresult[MAXN];
    int r = 0, o = 0;
    for (i = 0; i < MAXN; i++)
    {
        result[i] = overresult[i] = NULL;
    }

    int last_j = 0;
    for (i = 0; i < N; i++)
    {
        for (j = max(i, last_j); j < N; j++)
        {
            thissum += chain[j];
            if (thissum == M)
            {
                last_j = j;
                result[r] = (Pair)malloc(sizeof(struct PAIR));
                result[r]->i = i;
                result[r]->j = j;
                r++;
                if (i != last_j)
                {
                    thissum -= chain[i] + chain[last_j];
                }
                else
                {
                    thissum -= chain[last_j];
                }
                break;
            }
            else if (thissum > M)
            {
                last_j = j;
                if (r)
                {
                    if (i != last_j)
                    {
                        thissum -= chain[i] + chain[last_j];
                    }
                    else
                    {
                        thissum -= chain[last_j];
                    }
                    break;
                }
                else if (thissum < minoversum)
                {
                    minoversum = thissum;
                    o = 0;
                    if (overresult[o] == NULL)
                    {
                        overresult[o] = (Pair)malloc(sizeof(struct PAIR));
                    }
                    overresult[o]->i = i;
                    overresult[o]->j = j;
                    o++;
                }
                else if (thissum == minoversum)
                {
                    if (overresult[o] == NULL)
                    {
                        overresult[o] = (Pair)malloc(sizeof(struct PAIR));
                    }
                    overresult[o]->i = i;
                    overresult[o]->j = j;
                    o++;
                }
                if (i != last_j)
                {
                    thissum -= chain[i] + chain[last_j];
                }
                else
                {
                    thissum -= chain[last_j];
                }
                break;
            }
        }
        if (last_j == N - 1)
        {
            if (i != last_j)
            {
                thissum += chain[i] + chain[last_j];
            }
            else
            {
                thissum += chain[last_j];
            }
            for (; i < N; i++)
            {
                thissum -= chain[i];
                if (thissum < M)
                {
                    break;
                }
                else if (thissum == M)
                {
                    result[r] = (Pair)malloc(sizeof(struct PAIR));
                    result[r]->i = i+1;
                    result[r]->j = last_j;
                    r++;
                    break;
                }
                else
                {
                    if (thissum < minoversum)
                    {
                        minoversum = thissum;
                        o = 0;
                        if (overresult[o] == NULL)
                        {
                            overresult[o] = (Pair)malloc(sizeof(struct PAIR));
                        }
                        overresult[o]->i = i+1;
                        overresult[o]->j = last_j;
                        o++;
                    }
                    else if (thissum == minoversum)
                    {
                        if (overresult[o] == NULL)
                        {
                            overresult[o] = (Pair)malloc(sizeof(struct PAIR));
                        }
                        overresult[o]->i = i+1;
                        overresult[o]->j = last_j;
                        o++;
                    }
                }
            }
            break;
        }
    }

    if (!r)
    {
        for (i = 0; i < o; i++)
        {
            printf("%d-%d\n", overresult[i]->i+1, overresult[i]->j+1);
        }
    }
    else
    {
        for (i = 0; i < r; i++)
        {
            printf("%d-%d\n", result[i]->i+1, result[i]->j+1);
        }
    }
    return 0;
}
