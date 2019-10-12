/*
 @Date    : 2017-11-23 10:09:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
在此处添加文件说明
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct TNODE *Tree;
struct TNODE
{
    char data;
    Tree left;
    Tree right;
};

Tree Solve(char pre[], int pre_s, int pre_e, char in[], int in_s, int in_e)
{
    if (pre_e - pre_s < 0)
    {
        return NULL;
    }
    char root = pre[pre_s];
    Tree T;
    T = (Tree)malloc(sizeof(struct TNODE));
    T->left = T->right = NULL;
    T->data = root;
    if (pre_e - pre_s == 0)
    {
        return T;
    }
    int i;
    for (i = in_s; i <= in_e; i++)
    {
        if (in[i] == root)
        {
            break;
        }
    }
    int count_in;
    count_in = i - in_s;
    T->left = Solve(pre, pre_s+1, pre_s+count_in, in, in_s, i-1);
    T->right = Solve(pre, pre_s+count_in+1, pre_e, in, i+1, in_e);
    return T;
}

int GetHeight(Tree T)
{
    if (T)
    {
        int HL, HR, MAXH;
        HL = GetHeight(T->left);
        HR = GetHeight(T->right);
        MAXH = HL > HR ? HL : HR;
        return MAXH+1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int N;
    Tree T = NULL;
    scanf("%d", &N);
    char pre[N], in[N];
    int i;
    getchar();
    for (i = 0; i < N; i++)
    {
        scanf("%c", &pre[i]);
    }
    getchar();
    for (i = 0; i < N; i++)
    {
        scanf("%c", &in[i]);
    }
    T = Solve(pre, 0, N-1, in, 0, N-1);
    int h;
    h = GetHeight(T);
    printf("%d\n", h);
    return 0;
}
