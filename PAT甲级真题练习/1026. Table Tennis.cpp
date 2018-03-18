/*
 @Date    : 2018-03-17 20:36:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1026
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

static const int INF = 999999;

struct Pair
{
    int arriveTime, serveTime = INF, needTime;
    bool isVIP, isDelete = false;
};

struct Table
{
    int servedNum = 0;
    bool isVIP = false;
    int resTime = 0;
};

int time_to_int(const string &timeInfo)
{
    int res = stoi(timeInfo.substr(0, 2)) * 3600 + stoi(timeInfo.substr(3, 2)) * 60 +
    stoi(timeInfo.substr(6, 2));
    return res;
}

void int_to_time(char timeInfo[], int t)
{
    int h = t / 3600;
    int s = t % 60;
    int m = (t - h * 3600 - s) / 60;
    sprintf(timeInfo, "%02d:%02d:%02d", h, m, s);
    timeInfo[8] = '\0';
    return;
}

static int N, K, M;
static int nowTime = 0;
static vector<int> VIPT;

int find_VIP_pair(Pair P[], int d)
{
    for (unsigned i = d; i < N; ++i)
    {
        if (P[i].arriveTime > nowTime)
        {
            return -1;
        }
        if (P[i].isVIP && !P[i].isDelete)
        {
            return i;
        }
    }
    return -1;
}

int find_avail_table(Table T[], Pair P[], int d)
{
    int minRes = INF, tAvail;
    for (unsigned i = 0; i < K; ++i)
    {
        if (T[i].resTime < minRes)
        {
            tAvail = i;
            minRes = T[i].resTime;
        }
    }
    for (unsigned i = 0; i < K; ++i)
    {
        T[i].resTime -= minRes;
    }
    int VIP;
    nowTime += minRes;
    if ((VIP = find_VIP_pair(P, d)) != -1)
    {
        for (unsigned i = 0; i < M; ++i)
        {
            if (T[VIPT[i]].resTime == 0)
            {
                tAvail = VIPT[i];
                break;
            }
        }
    }
    return tAvail;
}

int main(int argc, char const *argv[])
{
    scanf("%d\n", &N);
    Pair P[N];
    for (unsigned i = 0; i < N; ++i)
    {
        char timeInfo[10];
        int needTime, VIP;
        scanf("%s %d %d", timeInfo, &needTime, &VIP);
        if (needTime > 120)
        {
            needTime = 120;
        }
        P[i].arriveTime = time_to_int(timeInfo);
        P[i].needTime = needTime * 60;
        P[i].isVIP = (VIP == 1);
    }
    scanf("%d %d", &K, &M);
    Table T[K];
    for (unsigned i = 0; i < M; ++i)
    {
        int vipTable;
        scanf("%d", &vipTable);
        T[vipTable-1].isVIP = true;
        VIPT.push_back(vipTable-1);
    }
    sort(P, P+N, [] (const Pair &p1, const Pair &p2)
        { return p1.arriveTime < p2.arriveTime; });
    int d = 0;
    nowTime = time_to_int("08:00:00");
    int closeTime = time_to_int("21:00:00");
    vector<int> servedSeq;
    while (d < N && servedSeq.size() < N)
    {
        int availT = find_avail_table(T, P, d), nextP;
        if ((T[availT].isVIP) && ((nextP = find_VIP_pair(P, d)) != -1))
        {
            P[nextP].isDelete = true;
        }
        else
        {
            for (; d != N &&P[d].isDelete == true; ++d);
            nextP = d;
            if (nowTime < P[nextP].arriveTime)
            {
                for (unsigned t = 0; t < K; ++t)
                {
                    T[t].resTime -= P[nextP].arriveTime - nowTime;
                    if (T[t].resTime < 0)
                    {
                        T[t].resTime = 0;
                    }
                }
                nowTime = P[nextP].arriveTime;
                availT = find_avail_table(T, P, d);
                int tempP;
                if ((T[availT].isVIP) && ((tempP = find_VIP_pair(P, d)) != -1))
                {
                    nextP = tempP;
                    P[nextP].isDelete = true;
                }
                else
                    ++d;
            }
            else
                ++d;
        }
        T[availT].resTime += P[nextP].needTime;
        P[nextP].serveTime = nowTime;
        servedSeq.push_back(nextP);
        if (P[nextP].serveTime >= closeTime)
        {
            break;
        }
        ++T[availT].servedNum;
    }
    for (auto &p : servedSeq)
    {
        if (P[p].serveTime >= closeTime)
        {
            break;
        }
        // printf("%d %d\n", p.arriveTime, p.serveTime);
        char timeInfo[10];
        int_to_time(timeInfo, P[p].arriveTime);
        printf("%s ", timeInfo);
        int_to_time(timeInfo, P[p].serveTime);
        printf("%s ", timeInfo);
        printf("%d\n", (P[p].serveTime - P[p].arriveTime + 30) / 60);
    }
    int output = 0;
    for (unsigned i = 0; i < K; ++i)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", T[i].servedNum);
    }
    putchar('\n');
    return 0;
}

