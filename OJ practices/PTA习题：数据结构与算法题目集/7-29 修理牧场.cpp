/*
 @Date    : 2018-03-14 12:01:50
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/856
哈夫曼编码问题，各个长度相当于权重
求最小哈夫曼树即就是使得权重大的被累加的次数少
注意优先队列使用时要确保比较函数的存在
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

static int totalWeight = 0;

struct HTNode
{
    int weight;
    shared_ptr<HTNode> left = nullptr, right = nullptr;
    HTNode(int w): weight(w) {}
};

bool cmp(const shared_ptr<HTNode> &p1, const shared_ptr<HTNode> &p2)
{
    return p1->weight > p2->weight;
}

shared_ptr<HTNode> my_merge(shared_ptr<HTNode> first, shared_ptr<HTNode> second)
{
    shared_ptr<HTNode> res(new HTNode(first->weight + second->weight));
    res->left = first; res->right = second;
    // printf("%d + %d -> %d\n", first->weight, second->weight, res->weight);
    return res;
}

void pre_traversal(const shared_ptr<HTNode> T)
{
    if (T && (T->left || T->right))
    {
        pre_traversal(T->left);
        pre_traversal(T->right);
        totalWeight += T->weight;
    }
    return;
}

int main(int argc, char const *argv[])
{
    priority_queue<shared_ptr<HTNode>, vector<shared_ptr<HTNode>>, decltype(cmp)*> Q(cmp);
    int N;
    scanf("%d", &N);
    while (N--)
    {
        int w;
        scanf("%d", &w);
        Q.push(make_shared<HTNode>(w));
        // printf("%d is in Q, now top is %d\n", w, Q.top()->weight);
    }
    while (Q.size() > 1)
    {
        auto first = Q.top(); Q.pop();
        auto second = Q.top(); Q.pop();
        // printf("%d %d is going to merge\n", first->weight, second->weight);
        Q.push(my_merge(first, second));
    }
    pre_traversal(Q.top());
    printf("%d\n", totalWeight);

    return 0;
}

