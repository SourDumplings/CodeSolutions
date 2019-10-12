/*
 @Date    : 2018-09-07 19:42:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/671
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

int N, M;
map<char, int> freqData;

struct TreeNode
{
    int f;
    char c;
    TreeNode *left = nullptr, *right = nullptr;
    bool codeNode = false;
};

class cmpNode
{
public:
    bool operator()(TreeNode *t1, TreeNode *t2)
    {
        return t1->f > t2->f;
    }
};

priority_queue<TreeNode*, vector<TreeNode*>, cmpNode> pQ;

TreeNode* build_H_tree()
{
    TreeNode *t = nullptr;
    while (pQ.size() > 1)
    {
        TreeNode *t1 = pQ.top(); pQ.pop();
        TreeNode *t2 = pQ.top(); pQ.pop();
        t = new TreeNode;
        t->f = t1->f + t2->f;
        t->left = t1;
        t->right = t2;
        pQ.push(t);
    }
    return t;
}

int wpl = 0;

int get_wpl(TreeNode *T, int l)
{
    if (T->left == nullptr && T->right == nullptr)
    {
        return T->f * l;
    }
    else
    {
        return get_wpl(T->left, l + 1) + get_wpl(T->right, l + 1);
    }
}

bool insert(TreeNode *&T, char code[], int cI, int l)
{
    if (T)
    {
        if (T->left == nullptr && T->right == nullptr && T->codeNode)
            return false;
        if (cI == l)
            return false;
    }
    else
    {
        T = new TreeNode;
    }

    if (cI < l)
    {
        if (code[cI] == '0')
        {
            return insert(T->left, code, cI+1, l);
        }
        else if (code[cI] == '1')
            return insert(T->right, code, cI+1, l);
    }
    else if (cI == l)
        T->codeNode = true;
    return true;
}

void free_tree(TreeNode *T)
{
    if (!T)
        return;
    queue<TreeNode*> q;
    q.push(T);
    while (!q.empty())
    {
        TreeNode *n = q.front(); q.pop();
        if (n->left)
            q.push(n->left);
        if (n->right)
            q.push(n->right);
        delete n;
    }
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        getchar();
        TreeNode *node = new TreeNode;
        scanf("%c %d", &node->c, &node->f);
        pQ.push(node);
        freqData[node->c] = node->f;
    }
    TreeNode *T = build_H_tree();
    wpl = get_wpl(T, 0);
    scanf("%d", &M);
    while (M--)
    {
        char c, code[65];
        int sumF = 0;
        TreeNode *t = new TreeNode;
        bool flag = true;
        for (int i = 0; i != N; ++i)
        {
            getchar();
            scanf("%c %s", &c, code);
            if (!flag)
                continue;
            sumF += strlen(code) * freqData[c];
            if (flag && (!insert(t, code, 0, strlen(code)) || sumF > wpl))
                flag = false;
        }
        if (flag)
        {
            printf("Yes\n");
        }
        else
            printf("No\n");
        free_tree(t);
    }
    free_tree(T);
    return 0;
}
