/*
 @Date    : 2018-02-23 21:28:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1107
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <array>

using namespace std;

static const int MAXK = 1001;
static const int MAXN = 1001;
static array<vector<int>, MAXK> hobbyData;
static vector<int> clusters;
static int N;
static bool checked[MAXN];

void find_friends(vector<vector<int>> &people, int p)
{
    checked[p] = true;
    ++clusters.back();
    for (int h : people[p])
    {
        for (int f : hobbyData[h])
        {
            if (!checked[f])
                find_friends(people, f);
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    vector<vector<int>> people(N);
    fill(checked, checked+N, false);
    int Ki, h;
    for (int i = 0; i != N; ++i)
    {
        scanf("%d:", &Ki);
        for (int j = 0; j != Ki; ++j)
        {
            scanf("%d", &h);
            people[i].push_back(h);
            hobbyData[h].push_back(i);
        }
    }
    for (int p = 0; p != N; ++p)
    {
        if (!checked[p])
        {
            clusters.push_back(0);
            find_friends(people, p);
        }
    }
    sort(clusters.rbegin(), clusters.rend());
    printf("%d\n", clusters.size());
    int output = 0;
    for (auto i : clusters)
    {
        if (output++) putchar(' ');
        printf("%d", i);
    }
    putchar('\n');
    return 0;
}
