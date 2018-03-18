/*
 @Date    : 2018-02-17 11:50:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1089
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

static const int MAXN = 101;
static int N;
static int origin[MAXN];
static int now[MAXN];

static int lastSeqPos;
char my_judge()
{
    int next;
    for (int i = 0; i != N - 1; ++i)
    {
        next = now[i+1];
        if (now[i] > next)
        {
            lastSeqPos = i;
            break;
        }
    }
    for (int i = lastSeqPos + 1; i != N; ++i)
    {
        if (now[i] != origin[i])
            return 'M';
    }
    return 'I';
}

void next_insertion()
{
    printf("Insertion Sort\n");
    int p = now[lastSeqPos+1];
    int i;
    for (i = lastSeqPos; i != -1 && now[i] > p; --i)
        now[i+1] = now[i];
    now[i+1] = p;
    return;
}

void next_merge()
{
    printf("Merge Sort\n");
    int maxT, last = now[0];
    for (int i = 1; i != N; ++i)
    {
        if (now[i] < last)
        {
            maxT = i;
            break;
        }
        last = now[i];
    }
    int tryT, T;
    for (tryT = maxT;;--tryT)
    {
        bool isTOK = true;
        for (int start = tryT; start < N; start += tryT)
        {
            last = now[start];
            for (int end = start; end != N && end != start + tryT; ++end)
            {
                if (now[end] < last)
                {
                    isTOK = false;
                    break;
                }
                last = now[end];
            }
            if (!isTOK)
                break;
        }
        if (isTOK)
        {
            T = tryT;
            break;
        }
    }
    T *= 2;
    for (int start = 0; start < N; start += T)
    {
        if (start + T < N)
            sort(now+start, now+start+T);
        else
        {
            sort(now+start, now+N);
            break;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
        scanf("%d", &origin[i]);
    for (int i = 0; i != N; ++i)
        scanf("%d", &now[i]);
    char judge = my_judge();
    switch (judge)
    {
        case 'I': next_insertion(); break;
        case 'M': next_merge(); break;
    }
    int output = 0;
    for (int i = 0; i != N; ++i)
    {
        if (output++)
            putchar(' ');
        printf("%d", now[i]);
    }
    putchar('\n');
    return 0;
}
