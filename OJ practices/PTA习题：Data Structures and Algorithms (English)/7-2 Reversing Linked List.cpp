/*
 @Date    : 2018-09-07 16:21:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/664
注意有可能有不在链表上的多余结点
 */

#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int N, K, start;
const int MAXN = 100005;

struct Node
{
    int add, value, next;
    Node() = default;
    Node(int add_, int value_, int next_): add(add_), value(value_), next(next_) {}
};

map<int, Node> data;
vector<int> L, res;

int main()
{
    scanf("%d %d %d", &start, &N, &K);
    for (int i = 0; i != N; ++i)
    {
        int add, value, next;
        scanf("%d %d %d", &add, &value, &next);
        data[add] = Node(add, value, next);
    }
    int tempStart = start;

    while (tempStart != -1)
    {
        L.push_back(tempStart);
        tempStart = data[tempStart].next;
    }

    N = L.size();
    int r = N % K;
    for (int i = 0; i != N; ++i)
    {
        if (i >= N - r)
            res.push_back(L[i]);
        else
        {
            res.push_back(L[(i / K + 1) * K - i % K - 1]);
        }
    }
    for (int i = 0; i != N - 1; ++i)
        data[res[i]].next = data[res[i+1]].add;
    data[res.back()].next = -1;
    for (int i = 0; i != N - 1; ++i)
    {
        int nodeI = res[i];
        printf("%05d %d %05d\n", data[nodeI].add, data[nodeI].value, data[nodeI].next);
    }
    printf("%05d %d -1\n", data[res.back()].add, data[res.back()].value);
    return 0;
}


