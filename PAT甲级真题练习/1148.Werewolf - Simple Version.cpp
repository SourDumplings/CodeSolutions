/*
 @Date    : 2018-09-11 08:12:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/1038429808099098624
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 105;
int s[MAXN], w[MAXN], N;

bool processLier(int l)
{
    if (s[l] < 0)
    {
        if (w[-s[l]] == 1)
            return false;
        w[-s[l]] = 0;
    }
    else
    {
        if (w[s[l]] == 0)
            return false;
        w[s[l]] = 1;
    }
    return true;
}

bool lie(int l1, int l2)
{
    if (!processLier(l1) || !processLier(l2))
        return false;
    for (int i = 1; i != N + 1; ++i)
    {
        if (i != l1 && i != l2)
        {
            if (s[i] < 0)
            {
                if (w[-s[i]] == 0)
                    return false;
                else
                    w[-s[i]] = 1;
            }
            else
            {
                if (w[s[i]] == 1)
                    return false;
                else
                    w[s[i]] = 0;
            }
        }
    }
    int wNum = count(w + 1, w + N + 1, 1);
    if (wNum > 2)
        return false;
    return true;
}

bool ok(int w1, int w2)
{
    for (int i = 1; i != N + 1; ++i)
    {
        if (i != w1 && i != w2)
        {
            fill(w, w + N + 1, -1);
            w[w1] = w[w2] = 1;
            if (lie(w1, i))
            {
                return true;
            }
            fill(w, w + N + 1, -1);
            w[w1] = w[w2] = 1;
            if (lie(w2, i))
            {
                return true;
            }
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 1; i != N + 1; ++i)
        scanf("%d", &s[i]);
    bool hasSolution = false;
    for (int i = 1; i != N + 1; ++i)
    {
        for (int j = i + 1; j != N + 1; ++j)
        {
            if (i != j && ok(i, j))
            {
                printf("%d %d\n", i, j);
                hasSolution = true;
                break;
            }
        }
        if (hasSolution) break;
    }
    if (!hasSolution)
        printf("No Solution\n");
    return 0;
}

