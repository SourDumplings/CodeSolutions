/*
 @Date    : 2018-02-20 18:29:55
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1097
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <memory>
#include <map>
#include <cmath>

using namespace std;

struct Node
{
    int addr, key, next;
};

void output(const vector<shared_ptr<Node>> &List)
{
    if (!List.empty())
    {
        auto it = List.begin();
        for (; it != List.end() - 1; ++it)
            printf("%05d %d %05d\n", (*it)->addr, (*it)->key, (*it)->next);
        printf("%05d %d -1\n", (*it)->addr, (*it)->key);
    }
    return;
}

void update(const vector<shared_ptr<Node>> &List)
{
    if (!List.empty())
    {
        auto it = List.begin();
        for (; it != List.end() - 1; ++it)
            (*it)->next = (*(it + 1))->addr;
        (*it)->next = -1;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N, startAddr;
    scanf("%d %d", &startAddr, &N);
    map<int, shared_ptr<Node>> data;
    for (int i = 0; i != N; ++i)
    {
        shared_ptr<Node> tempNode(new Node);
        scanf("%d %d %d", &tempNode->addr, &tempNode->key, &tempNode->next);
        data[tempNode->addr] = tempNode;
    }

    vector<shared_ptr<Node>> originList;
    vector<shared_ptr<Node>> removedList;
    map<int, int> occurData;
    do
    {
        shared_ptr<Node> now = data[startAddr];
        if (occurData[abs(now->key)] == 1)
            removedList.push_back(now);
        else
        {
            originList.push_back(now);
            occurData[abs(now->key)] = 1;
        }
        startAddr = now->next;
    } while (startAddr != -1);

    update(originList);
    update(removedList);

    output(originList);
    output(removedList);
    return 0;
}
