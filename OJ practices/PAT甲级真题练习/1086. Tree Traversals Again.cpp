/*
 @Date    : 2018-02-16 18:46:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1086
push序列就是个先序遍历
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <memory>

using namespace std;

struct TNode
{
    int data;
    shared_ptr<TNode> left = nullptr, right = nullptr;
    TNode(int d): data(d) {}
};

shared_ptr<TNode> build_tree(shared_ptr<TNode> &T, const vector<int> &pushSeq,
    int ps, int pe, const vector<int> &in, int ins, int ine)
{
    if (pe == ps)
        return nullptr;
    int root = pushSeq[ps];
    T = make_shared<TNode>(root);
    int inle;
    for (int i = ins; i != ine; ++i)
    {
        if (in[i] == root)
        {
            inle = i;
            break;
        }
    }
    int ll = inle - ins;
    T->left = build_tree(T->left, pushSeq, ps+1, ps+1+ll, in, ins, inle);
    T->right = build_tree(T->right, pushSeq, ps+1+ll, pe, in, inle+1, ine);
    return T;
}

static int output = 0;
void post_traversal(const shared_ptr<TNode> &T)
{
    if (T != nullptr)
    {
        post_traversal(T->left);
        post_traversal(T->right);
        if (output++)
            putchar(' ');
        printf("%d", T->data);
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    char order[10];
    int num;
    vector<int> pushSeq;
    stack<int> S;
    vector<int> in;
    for (int i = 0; i != 2 * N; ++i)
    {
        scanf("%s", order);
        if (order[1] == 'u')
        {
            scanf("%d", &num);
            S.push(num);
            pushSeq.push_back(num);
        }
        else if (order[1] == 'o')
        {
            in.push_back(S.top());
            S.pop();
        }
    }
    shared_ptr<TNode> T;
    T = build_tree(T, pushSeq, 0, N, in, 0, N);
    post_traversal(T);
    putchar('\n');
    return 0;
}
