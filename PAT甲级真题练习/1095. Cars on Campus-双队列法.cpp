/*
 @Date    : 2018-09-02 23:11:53
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805371602845696
 */

#include <iostream>
#include <cstdio>
#include <deque>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int N, K;

struct Record
{
    string plate;
    int T;
    char type;
    Record(const string &p, int t, char ty): plate(p), T(t), type(ty) {}
    Record() = default;
};

deque<Record> inQ, outQ, Q;
map<string, int> parkT;

string seconds_to_time(int seconds)
{
    int h = seconds / 3600;
    int s = seconds % 60;
    int m = (seconds - h * 3600 - s) / 60;
    char ret[9];
    sprintf(ret, "%02d:%02d:%02d", h, m, s);
    return string(ret);
}

inline int time_to_seconds(const string &t)
{
    int ret = (t[0] - '0') * 36000 + (t[1] - '0') * 3600 + (t[3] - '0') * 600 +
        (t[4] - '0') * 60 + (t[6] - '0') * 10 + t[7] - '0';
    return ret;
}

void pre_treat()
{
    for (int i = 0; i != N; ++i)
    {
        if (Q[i].type == 'i' && (i != N -1 && Q[i+1].type == 'o' && Q[i+1].plate == Q[i].plate &&
                                 Q[i+1].T > Q[i].T))
        {
            inQ.push_back(Q[i]);
            outQ.push_back(Q[i+1]);
            ++i;
        }
    }
    return;
}

int main()
{
    cin >> N >> K;
    for (int i = 0; i != N; ++i)
    {
        string p, T, order;
        cin >> p >> T >> order;
        Q.push_back(Record(p, time_to_seconds(T), order[0]));
    }
    sort(Q.begin(), Q.end(), [] (const Record &r1, const Record &r2)
         {
            if (r1.plate == r2.plate)
                return r1.T < r2.T;
            else
                return r1.plate < r2.plate;
         });
    pre_treat();
    sort(inQ.begin(), inQ.end(), [] (const Record &r1, const Record &r2)
         {
             return r1.T < r2.T;
         });
    sort(outQ.begin(), outQ.end(), [] (const Record &r1, const Record &r2)
         {
             return r1.T < r2.T;
         });

    int maxT = 24 * 3600 + 1, carNum = 0;
    deque<int> query(K);
    for (int i = 0; i != K; ++i)
    {
        string T;
        cin >> T;
        query[i] = time_to_seconds(T);
    }

    map<string, int> inT;
    for (int t = inQ.front().T; t != maxT + 1; ++t)
    {
        while (!inQ.empty() && t == inQ.front().T)
        {
            ++carNum;
            inT[inQ.front().plate] = t;
            inQ.pop_front();
        }
        while (!outQ.empty() && t == outQ.front().T)
        {
            --carNum;
            parkT[outQ.front().plate] += t - inT[outQ.front().plate];
            outQ.pop_front();
        }

        if (!query.empty() && t == query.front())
        {
            printf("%d\n", carNum);
            query.pop_front();
        }
    }

    int maxParkT = 0;
    for (auto &carP : parkT)
    {
        if (carP.second > maxParkT)
            maxParkT = carP.second;
    }
    for (auto &carP : parkT)
    {
        if (carP.second == maxParkT)
            printf("%s ", carP.first.c_str());
    }
    printf("%s\n", seconds_to_time(maxParkT).c_str());
    return 0;
}


