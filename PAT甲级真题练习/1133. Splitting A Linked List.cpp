/*
 @Date    : 2018-03-06 19:01:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1133
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>

using namespace std;

struct Node
{
    int addr, data, next;
};

static map<int, shared_ptr<Node>> addrData;
static vector<shared_ptr<Node>> list;
static int startAddr, N, K;

int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &startAddr, &N, &K);
    for (int i = 0; i != N; ++i)
    {
        auto p = make_shared<Node>();
        scanf("%d %d %d", &p->addr, &p->data, &p->next);
        addrData.insert(make_pair(p->addr, p));
    }
    while (startAddr != -1)
    {
        list.push_back(addrData[startAddr]);
        startAddr = list.back()->next;
    }
    stable_partition(list.begin(), list.end(),
        [] (const shared_ptr<Node> &p)
        { return p->data <= K; });
    stable_partition(list.begin(), list.end(),
    [] (const shared_ptr<Node> &p)
    { return p->data < 0; });
    startAddr = list.front()->addr;
    for (int i = 0; i != list.size() - 1; ++i)
        list[i]->next = list[i+1]->addr;
    list.back()->next = -1;
    for (auto p : list)
    {
        if (p->next != -1)
            printf("%05d %d %05d\n", p->addr, p->data, p->next);
        else
            printf("%05d %d -1\n", p->addr, p->data);
    }
    return 0;
}

