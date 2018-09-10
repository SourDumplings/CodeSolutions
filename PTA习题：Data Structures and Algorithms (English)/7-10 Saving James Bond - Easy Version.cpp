/*
 @Date    : 2018-09-07 21:39:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/672
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int N, D;
const int MAXN = 105;
int d = 15;

struct Cro
{
    double x, y;
};

Cro C[MAXN];
bool visited[MAXN];

bool can_escape(int c)
{
    return fabs(50 - C[c].x) <= D || fabs(-50 - C[c].x) <= D || fabs(50 - C[c].y) <= D || fabs(50 - C[c].y) <= D;
}

bool dfs(int c)
{
    if (can_escape(c))
        return true;
    else
    {
        for (int i = 0; i != N; ++i)
        {
            if (visited[i])
                continue;
            double dist2 = (C[i].x - C[c].x) * (C[i].x - C[c].x) + (C[i].y - C[c].y) * (C[i].y - C[c].y);
            if (sqrt(dist2) <= D)
            {
                visited[i] = true;
                if(dfs(i))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d %d", &N, &D);
    for (int i = 0; i != N; ++i)
    {
        scanf("%lf %lf", &C[i].x, &C[i].y);
    }
    if (D >= 50 - (double)d / 2)
        printf("Yes\n");
    else
    {
        bool flag = false;
        fill(visited, visited + N, false);
        for (int i = 0; i != N; ++i)
        {
            if (visited[i])
                continue;
            double dist2 = C[i].x * C[i].x + C[i].y * C[i].y;
            if (sqrt(dist2) - (double)d / 2 <= D)
            {
                visited[i] = true;
                if (dfs(i))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
