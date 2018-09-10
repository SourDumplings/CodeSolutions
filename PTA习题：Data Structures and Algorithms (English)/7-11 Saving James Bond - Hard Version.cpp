/*
 @Date    : 2018-09-07 22:48:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/673
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int N, D;
const int MAXN = 105, INF = 99999, d = 15;

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

int minJump = INF, thisJump = 0, thisFirstJump, minFirstJump = INF;
vector<int> thisPath, resPath;
bool canEscape = false;

void dfs(int c)
{
    if (thisJump > minJump)
        return;
    if (can_escape(c))
    {
        canEscape = true;
        ++thisJump;
        if (thisJump < minJump || (thisJump == minJump && thisFirstJump < minFirstJump))
        {
            minFirstJump = thisFirstJump;
            minJump = thisJump;
            resPath = thisPath;
        }
        --thisJump;
    }
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
                ++thisJump;
                thisPath.push_back(i);
                dfs(i);
                --thisJump;
                thisPath.pop_back();
                visited[i] = false;
            }
        }
    }
    return;
}

void print_path()
{
    for (auto it = resPath.begin(); it != resPath.end(); ++it)
    {
        printf("%d %d\n", (int)(C[*it].x), (int)(C[*it].y));
    }
    return;
}

int main()
{
    scanf("%d %d", &N, &D);
    for (int i = 0; i != N; ++i)
    {
        scanf("%lf %lf", &C[i].x, &C[i].y);
    }
    if (D >= 50 - (double)d / 2)
        printf("1\n");
    else
    {
        fill(visited, visited + N, false);
        for (int i = 0; i != N; ++i)
        {
            if (visited[i])
                continue;
            double dist2 = C[i].x * C[i].x + C[i].y * C[i].y;
            if (sqrt(dist2) - (double)d / 2 <= D)
            {
                thisFirstJump = sqrt(dist2) - (double)d / 2;
                visited[i] = true;
                ++thisJump;
                thisPath.push_back(i);
                dfs(i);
                --thisJump;
                thisPath.pop_back();
            }
        }
        if (canEscape)
        {
            printf("%d\n", minJump);
            print_path();
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
