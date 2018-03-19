#include <stdio.h>
#include <stdlib.h>

const int SZ = 1 << 20;  //提升IO buff
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin, inbuf, _IOFBF, SZ);
        setvbuf(stdout, outbuf, _IOFBF, SZ);
    }
}io;

#define N 4000001

struct Node
{
    Node *lchild, *rchild;
    int val;
}nodes[N];

int loc;
Node *creat()
{
    nodes[loc].lchild = nodes[loc].rchild = NULL;
    return &nodes[loc++];
}

int pre[N], post[N];

Node *build(int s1, int e1, int s2, int e2)
{  // 前序序列[s1,e1]，后序序列[s2,e2]
    Node *root = creat();
    root->val = pre[s1];
    int rootIdx;
    if (s2 == e2) return root;
    for (int i = s2; i <= e2; i++)  // 寻找左子树树根结点在后序序列的位置
    {
        if (post[i] == pre[s1 + 1]) // pre[s+1]：左子树树根
        {
            rootIdx = i;
            break;
        }
    }
    root->lchild = build(s1 + 1, rootIdx - s2 + s1 + 1, s2, rootIdx);
    root->rchild = build(rootIdx - s2 + s1 + 2, e1, rootIdx + 1, e2 - 1);
    return root;
}

void inOrder(Node *tree)  //
{
    if (tree->lchild != NULL) inOrder(tree->lchild);
    printf("%d ", tree->val);
    if (tree->rchild != NULL) inOrder(tree->rchild);
}

int main()
{
    int n;
    loc = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &post[i]);
    Node *tree = build(0, n - 1, 0, n - 1);
    inOrder(tree);
    //system("pause");
    return 0;
}
