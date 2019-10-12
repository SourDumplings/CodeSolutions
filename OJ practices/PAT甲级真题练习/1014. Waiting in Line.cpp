/*
 @Date    : 2018-03-17 13:17:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1014
注意是17:00之前开始服务的顾客输出结束时间，
否则说Sorry
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

struct Customer
{
    int serveTime, needTime;
};

struct Window
{
    int resTime = 0;
    queue<int> wQ;
};

static const int MAXN = 21, MAXK = 1001, INF = INT32_MAX;
static int N, M, K, Q;
static Customer C[MAXK];
static Window W[MAXN];

static int nowTime = 0;

int find_avail_window()
{
    int minResTime = INF, availW = 0;
    for (unsigned w = 0; w < N; ++w)
    {
        if (W[w].resTime < minResTime)
        {
            minResTime = W[w].resTime;
            availW = w;
        }
    }
    for (unsigned w = 0; w < N; ++w)
    {
        if (W[w].resTime != INF)
        {
            W[w].resTime -= minResTime;
        }
    }
    nowTime += minResTime;
    return availW;
}

void print_time(int minutes)
{
    int h = minutes / 60;
    int minR = minutes - h * 60;
    printf("%02d:%02d\n", h + 8, minR);
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d", &N, &M, &K, &Q);
    for (unsigned i = 0; i < K; ++i)
    {
        scanf("%d", &C[i].needTime);
    }
    int outC, w = 0;
    for (outC = 0; outC < K && outC < N * M; ++outC)
    {
        W[w].wQ.push(outC);
        w = (w + 1) % N;
    }
    int servedNum = 0;
    for (unsigned w = 0; w < N && !W[w].wQ.empty(); ++w)
    {
        W[w].resTime = C[W[w].wQ.front()].needTime;
        C[W[w].wQ.front()].serveTime = 0;
        W[w].wQ.pop();
        ++servedNum;
    }
    while (servedNum < K)
    {
        int w = find_avail_window();
        if (W[w].wQ.empty() && outC == K)
        {
            W[w].resTime = INF;
            continue;
        }
        int nextC = W[w].wQ.front(); W[w].wQ.pop();
        C[nextC].serveTime = nowTime;
        // printf("%d is served at %d\n", nextC+1, nowTime);
        W[w].resTime = C[nextC].needTime;
        if (outC < K)
        {
            // printf("at time %d, %d goes to wW %d\n", nowTime, outC+1, w);
            W[w].wQ.push(outC++);
        }
        ++servedNum;
    }
    for (unsigned i = 0; i < Q; ++i)
    {
        int c;
        scanf("%d", &c);
        if (C[c-1].serveTime >= 540)
        {
            printf("Sorry\n");
        }
        else
            print_time(C[c-1].serveTime + C[c-1].needTime);
    }
    return 0;
}

