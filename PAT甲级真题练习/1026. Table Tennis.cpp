/*
 @Date    : 2018-08-25 00:30:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805472333250560
 */

#include <iostream>
#include <cstdio>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

int N, K, M;
const int MAXN = 10005, MAXK = 105, INF = 999999;

struct Pair
{
    int arriveTime, serveTime = INF, waitTime;
    int playTime;
    bool isVIP = false;
    bool served = false;
};

struct Table
{
    int resTime = 0;
    bool isVIPTable = false;
    int servedNum = 0;
};

Table T[MAXK];
int nowTime = 0;
deque<int> Q, vipQ;
Pair P[MAXN];

int find_avail_table()
{
    int minRes = INF, availW = -1;
    for (int i = 0; i != K; ++i)
    {
        if (T[i].resTime < minRes)
        {
            minRes = T[i].resTime;
            availW = i;
        }
    }
    nowTime += minRes;
    for (int i = 0; i != K; ++i)
    {
        T[i].resTime -= minRes;
    }

    bool hasVIP = false;
    if (!vipQ.empty() && P[vipQ.front()].arriveTime <= nowTime)
        hasVIP = true;
    if (hasVIP)
    {
        for (int i = 0; i != K; ++i)
        {
            if (T[i].resTime == 0 && T[i].isVIPTable)
            {
                availW = i;
                break;
            }
        }
    }
    return availW;
}

int processTime(char aT[])
{
    int h = (aT[0] - '0') * 10 + (aT[1] - '0');
    int m = (aT[3] - '0') * 10 + (aT[4] - '0');
    int s = (aT[6] - '0') * 10 + (aT[7] - '0');
    return (h - 8) * 3600 + m * 60 + s;

}

string get_time(int st)
{
    int h = st / 3600;
    int s = st % 60;
    int m = (st - h * 3600 - s) / 60;
    char ss[20];
    sprintf(ss, "%02d:%02d:%02d", h + 8, m, s);
    return string(ss);
}

void output_pair(const Pair &p)
{
    printf("%s %s %d\n", get_time(p.arriveTime).c_str(), get_time(p.serveTime).c_str(),
           (p.serveTime - p.arriveTime + 30) / 60);
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        char aT[20];
        int pT, v;
        scanf("%s %d %d", aT, &pT, &v);
        if (pT > 120) pT = 120;
        P[i].arriveTime = processTime(aT);
        P[i].playTime = pT * 60;
        if (v == 1)
        {
            P[i].isVIP = true;
        }
    }
    sort(P, P+N, [] (const Pair &p1, const Pair &p2) { return p1.arriveTime < p2.arriveTime; });
    for (int i = 0; i != N; ++i)
    {
        Q.push_back(i);
        if (P[i].isVIP)
        {
            vipQ.push_back(i);
        }
    }

    scanf("%d %d", &K, &M);
    for (int i = 0; i != M; ++i)
    {
        int v;
        scanf("%d", &v);
        T[v-1].isVIPTable = true;
    }

    deque<int> serveSeq;
    while (!Q.empty())
    {
        while (!vipQ.empty() && P[vipQ.front()].served)
            vipQ.pop_front();
        while (!Q.empty() && P[Q.front()].served)
            Q.pop_front();
        if (Q.empty()) break;

        int w = find_avail_table();
        int nextP = Q.front();
        if (P[nextP].arriveTime > nowTime)
        {
            for (int i = 0; i != K; ++i)
            {
                if (T[i].resTime < P[nextP].arriveTime - nowTime)
                    T[i].resTime = 0;
                else
                    T[i].resTime -= P[nextP].arriveTime - nowTime;
            }
            nowTime = P[nextP].arriveTime;
            w = find_avail_table();
        }
        if (nowTime >= 13 * 3600) break;

        if (T[w].isVIPTable && !vipQ.empty() && P[vipQ.front()].arriveTime <= nowTime)
        {
            nextP = vipQ.front();
            vipQ.pop_front();
        }
        else
            Q.pop_front();
        T[w].resTime = P[nextP].playTime;
        ++T[w].servedNum;
        P[nextP].serveTime = nowTime;
        P[nextP].served = true;
        serveSeq.push_back(nextP);
    }

    for (auto i : serveSeq)
    {
        output_pair(P[i]);
    }

    int output = 0;
    for (int i = 0; i != K; ++i)
    {
        if (output++)
            putchar(' ');
        printf("%d", T[i].servedNum);
    }
    putchar('\n');

    return 0;
}
