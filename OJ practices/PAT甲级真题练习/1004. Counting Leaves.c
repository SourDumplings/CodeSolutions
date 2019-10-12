/*
 @Date    : 2017-11-27 11:12:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1004
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100

typedef struct TREENODE *Tree;
struct TREENODE
{
    Tree children[MAXN+1];
    int isleaf;
};

int N, M;
Tree T[MAXN+1];
int leaves[MAXN];

void LevelOrderTraversal(int root, int level)
{
    int i;
    if (leaves[level] == -1)
    {
        leaves[level] = 0;
    }
    if (T[root]->isleaf)
    {
        leaves[level]++;
        return;
    }
    for (i = 1; i <= N; i++)
    {
        if (T[root]->children[i])
        {
            LevelOrderTraversal(i, level+1);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    int i, K, j, id, id_c;
    char ID[3];
    for (i = 0; i <= N; i++)
    {
        T[i] = (Tree)malloc(sizeof(struct TREENODE));
        T[i]->isleaf = 1;
        for (j = 0; j <= N; j++)
        {
            T[i]->children[j] = NULL;
        }
        leaves[i] = -1;
    }

    for (i = 0; i < M; i++)
    {
        scanf("%s %d", ID, &K);
        id = atoi(ID);
        T[id]->isleaf = 0;
        for (j = 0; j < K; j++)
        {
            scanf("%s", ID);
            id_c = atoi(ID);
            T[id]->children[id_c] = T[id_c];
        }
    }

    LevelOrderTraversal(1, 0);

    int output = 0;
    for (i = 0; i < N && leaves[i] != -1; i++)
    {
        if (output++)
        {
            putchar(' ');
        }
        printf("%d", leaves[i]);
    }
    putchar('\n');

    return 0;
}

