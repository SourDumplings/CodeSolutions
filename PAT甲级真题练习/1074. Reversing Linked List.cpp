/*
 @Date    : 2018-02-09 11:35:33
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1074
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <memory>

using namespace std;

struct Node
{
    Node(int a, int d, int n): addr(a), data(d), next(n) {}
    int addr, data, next;
};


int main(int argc, char const *argv[])
{
    map<int, shared_ptr<Node>> d;
    vector<shared_ptr<Node>> vl;
    int startAddr, N, K;
    scanf("%d %d %d", &startAddr, &N, &K);
    for (int i = 0; i != N; ++i)
    {
        int addr, data, next;
        scanf("%d %d %d", &addr, &data, &next);
        d.insert(make_pair(addr, make_shared<Node>(addr, data, next)));
    }
    for (int i = 0; i != N; ++i)
    {
        vl.push_back(d[startAddr]);
        startAddr = vl.back()->next;
        if (startAddr == -1)
            break;
    }
    for (unsigned i = 0; i + K <= vl.size(); i += K)
        reverse(vl.begin() + i, vl.begin() + i + K);
    for (unsigned i = 0; i != vl.size() - 1; ++i)
    {
        vl[i]->next = vl[i+1]->addr;
    }
    vl.back()->next = -1;
    for (unsigned i = 0; i != vl.size() - 1; ++i)
        printf("%05d %d %05d\n", vl[i]->addr, vl[i]->data, vl[i]->next);
    printf("%05d %d -1\n", vl.back()->addr, vl.back()->data);

    return 0;
}
