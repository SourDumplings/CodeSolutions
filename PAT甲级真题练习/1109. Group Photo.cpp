/*
 @Date    : 2018-02-26 15:32:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1109
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

struct People
{
    int height;
    char name[10];
};

static int N, K;

bool cmp(const People &p1, const People &p2)
{
    if (p1.height == p2.height)
        return strcmp(p1.name, p2.name) > 0;
    return p1.height < p2.height;
}

void enQueue(vector<deque<People*>> &formation, int q, People data[],
    int b, int e)
{
    formation[q].push_back(&data[e-1]);
    bool left = true;
    for (int i = e - 2; i >= b; --i)
    {
        if (left)
        {
            formation[q].push_front(&data[i]);
            left = false;
        }
        else
        {
            formation[q].push_back(&data[i]);
            left = true;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &K);
    People data[N];
    for (int i = 0; i != N; ++i)
        scanf("%s %d", data[i].name, &data[i].height);
    sort(data, data+N, cmp);
    int next;
    vector<deque<People*>> formation;
    int eachRowNum = N / K, q = 0;
    for (next = 0; next != N;)
    {
        formation.push_back(deque<People*>());
        if (N - next >= 2 * eachRowNum)
        {
            enQueue(formation, q++, data, next, next + eachRowNum);
            next += eachRowNum;
        }
        else
        {
            enQueue(formation, q, data, next, N);
            break;
        }
    }
    for (auto it_q = formation.rbegin(); it_q != formation.rend();
        ++it_q)
    {
        int output = 0;
        for (const auto &p : *it_q)
        {
            if (output++) putchar(' ');
            printf("%s", p->name);
        }
        putchar('\n');
    }
    return 0;
}
