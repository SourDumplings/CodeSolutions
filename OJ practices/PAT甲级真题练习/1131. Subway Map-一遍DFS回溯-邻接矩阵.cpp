/*
 @Date    : 2018-03-06 15:05:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1131
差点就内存超限了
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

static const int MAXM = 10000;
static const int INF = 9999999;

static int line[MAXM][MAXM];

static int minDist = INF;
static int thisTransfer = 0, minTransfer = INF, lastLine = INF;
static vector<int> thisPath, resPath;
static bool visited[MAXM];
static vector<vector<int>> G(MAXM);

void DFS(int s, int d, int thisDist)
{
    thisPath.push_back(d);
    visited[d] = true;
    if (d == s)
    {
        if (thisDist < minDist || (thisDist == minDist && thisTransfer < minTransfer))
        {
            minDist = thisDist;
            minTransfer = thisTransfer;
            resPath = thisPath;
        }
    }
    else if (thisDist < minDist || (thisDist == minDist && thisTransfer < minTransfer))
    {
        for (int i : G[d])
        {
            if (!visited[i])
            {
                int tempLastLine = lastLine;
                if (line[i][d] != lastLine)
                {
                    lastLine = line[i][d];
                    ++thisTransfer;
                }
                DFS(s, i, thisDist + 1);
                if (lastLine != tempLastLine)
                {
                    lastLine = tempLastLine;
                    --thisTransfer;
                }
            }
        }
    }
    thisPath.pop_back();
    visited[d] = false;
    return;
}

void output_path()
{
    printf("%d\n", minDist);
    int lastLine = line[resPath[minDist]][resPath[minDist-1]];
    int lastStop = resPath[minDist];
    for (int i = minDist; i != -1; --i)
    {
        if (i != minDist)
        {
            if (line[resPath[i+1]][resPath[i]] != lastLine)
            {
                printf("Take Line#%d from %04d to %04d.\n",
                    lastLine, lastStop, resPath[i+1]);
                lastLine = line[resPath[i+1]][resPath[i]];
                lastStop = resPath[i+1];
            }
            if (i == 0)
                printf("Take Line#%d from %04d to %04d.\n",
                    lastLine, lastStop, resPath[i]);
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for (int lineNo = 0; lineNo != N; ++lineNo)
    {
        int M;
        scanf("%d", &M);
        int lastS, S;
        for (int i = 0; i != M; ++i)
        {
            scanf("%d", &S);
            if (i != 0)
            {
                line[S][lastS] = line[lastS][S] = lineNo + 1;
                G[S].push_back(lastS);
                G[lastS].push_back(S);
            }
            lastS = S;
        }
    }
    int K, s, d;
    scanf("%d", &K);
    while (K--)
    {
        thisTransfer = 0;
        minTransfer = lastLine = minDist = INF;
        fill(visited, visited+MAXM, false);
        scanf("%d %d", &s, &d);
        DFS(s, d, 0);
        output_path();
    }
    return 0;
}

