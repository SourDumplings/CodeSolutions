/*
 @Date    : 2018-03-16 16:57:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/895
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

static unordered_map<string, int> circleData;
static int N, M;

struct Person
{
    char name[4];
    int arriveTime;
    int serviceTime;
};

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (unsigned i = 0; i < M; ++i)
    {
        int K;
        scanf("%d", &K);
        for (unsigned j = 0; j < K; ++j)
        {
            char name[4];
            scanf("%s", name);
            circleData[string(name)] = i + 1;
        }
    }
    list<Person> Q;
    for (unsigned i = 0; i < N; ++i)
    {
        Person p;
        scanf("%s %d %d", p.name, &p.arriveTime, &p.serviceTime);
        if (p.serviceTime > 60)
        {
            p.serviceTime = 60;
        }
        Q.push_back(std::move(p));
    }
    int nowTime = 0;
    int totalWaitTime = 0;
    bool cutIn = false;
    vector<string> serviceSeq;
    Person nextPerson;
    while (true)
    {
        if (!cutIn)
        {
            if (Q.empty())
            {
                break;
            }
            nextPerson = std::move(Q.front()); Q.pop_front();
        }
        cutIn = false;
        // printf("%s is served\n", nextPerson.name);
        serviceSeq.push_back(nextPerson.name);
        // printf("%s is waited for %d\n", nextPerson.name, nowTime - nextPerson.arriveTime);
        if (nowTime < nextPerson.arriveTime)
        {
            nowTime = nextPerson.arriveTime;
        }
        totalWaitTime += nowTime - nextPerson.arriveTime;
        nowTime += nextPerson.serviceTime;
        for (auto it = Q.begin(); it != Q.end(); ++it)
        {
            if (it->arriveTime > nowTime)
            {
                break;
            }
            else if (circleData[it->name] != 0 &&
                circleData[it->name] == circleData[nextPerson.name])
            {
                // printf("%s is %s's friend\n", it->name, nextPerson.name);
                nextPerson = *it;
                Q.erase(it);
                cutIn = true;
                break;
            }
        }
    }
    for (auto &name : serviceSeq)
    {
        printf("%s\n", name.c_str());
    }
    printf("%.1f\n", static_cast<double>(totalWaitTime) / N);
    return 0;
}

