/*
 @Date    : 2018-09-05 22:03:37
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805347523346432
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 999999, MAXS = 10000;

struct Edge
{
    Edge() = default;
    Edge(int w_, int l_): w(w_), lineNo(l_) {}
    int w;
    int lineNo;
};

vector<Edge> G[MAXS];
int N, M, K, s, d;
int thisDist = 0, resDist = INF;

struct TransInfo
{
    int start, stop;
    int lineNo;
    TransInfo() = default;
    TransInfo(int s, int st, int l): start(s), stop(st), lineNo(l) {}
};

vector<TransInfo> thisTransfer, minTransfer;
bool visited[MAXS];

void dfs(int w, int lineStart, int lineNo)
{
    ++thisDist;
    if (w == s && thisDist <= resDist)
    {
        thisTransfer.push_back(TransInfo(lineStart, w, lineNo));
        if (thisDist < resDist ||
            (thisDist == resDist && thisTransfer.size() < minTransfer.size()))
        {
            resDist = thisDist;
            minTransfer = thisTransfer;
        }
        thisTransfer.pop_back();
    }
    else if (thisDist < resDist)
    {
        int tempLineStart = lineStart;
        for (auto &eV : G[w])
        {
            if (eV.w == w || visited[eV.w])
                continue;
            if (eV.lineNo != lineNo)
            {
                thisTransfer.push_back(TransInfo(lineStart, w, lineNo));
                lineStart = w;
            }
            visited[eV.w] = true;
            dfs(eV.w, lineStart, eV.lineNo);
            visited[eV.w] = false;
            if (eV.lineNo != lineNo)
            {
                thisTransfer.pop_back();
                lineStart = tempLineStart;
            }
        }
    }
    --thisDist;
    return;
}

void print_path()
{
    printf("%d\n", resDist);
    for (auto it = minTransfer.rbegin(); it != minTransfer.rend(); ++it)
    {
        printf("Take Line#%d from %04d to %04d.\n", it->lineNo, it->stop, it->start);
    }
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        scanf("%d", &M);
        bool start = true;
        int lastSt, st;
        for (int j = 0; j != M; ++j)
        {
            scanf("%d", &st);
            if (start)
                start = false;
            else
            {
                G[lastSt].push_back(Edge(st, i+1));
                G[st].push_back(Edge(lastSt, i+1));
            }
            lastSt = st;
        }
    }
    scanf("%d", &K);
    for (int i = 0; i != K; ++i)
    {
        thisDist = 0;
        resDist = INF;
        thisTransfer.clear();
        minTransfer.clear();
        fill(visited, visited+MAXS, false);
        scanf("%d %d", &s, &d);
        for (auto &eV : G[d])
        {
            visited[eV.w] = true;
            dfs(eV.w, d, eV.lineNo);
            visited[eV.w] = false;
        }
        print_path();
    }
    return 0;
}


