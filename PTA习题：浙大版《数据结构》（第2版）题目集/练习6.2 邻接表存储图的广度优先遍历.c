/*
 @Date    : 2017-11-21 11:15:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/6475
 */

#include <stdio.h>

typedef enum {false, true} bool;
#define MaxVertexNum 10   /* 最大顶点数设为10 */
typedef int Vertex;       /* 用顶点下标表示顶点,为整型 */

/* 邻接点的定义 */
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
    Vertex AdjV;        /* 邻接点下标 */
    PtrToAdjVNode Next; /* 指向下一个邻接点的指针 */
};

/* 顶点表头结点的定义 */
typedef struct Vnode{
    PtrToAdjVNode FirstEdge; /* 边表头指针 */
} AdjList[MaxVertexNum];     /* AdjList是邻接表类型 */

/* 图结点的定义 */
typedef struct GNode *PtrToGNode;
struct GNode{
    int Nv;     /* 顶点数 */
    int Ne;     /* 边数   */
    AdjList G;  /* 邻接表 */
};
typedef PtrToGNode LGraph; /* 以邻接表方式存储的图类型 */

bool Visited[MaxVertexNum]; /* 顶点的访问标记 */

LGraph CreateGraph(); /* 创建图并且将Visited初始化为false；裁判实现，细节不表 */

void Visit( Vertex V )
{
    printf(" %d", V);
}

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) );

int main()
{
    LGraph G;
    Vertex S;

    G = CreateGraph();
    scanf("%d", &S);
    printf("BFS from %d:", S);
    BFS(G, S, Visit);

    return 0;
}

#include <stdlib.h>
LGraph CreateGraph()
{
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct GNode));
    int Nv, Ne;
    scanf("%d %d", &Nv, &Ne);
    Graph->Nv = Nv;
    Graph->Ne = Ne;
    int i;
    Vertex V, W;
    PtrToAdjVNode temp;
    for (V = 0; V < Nv; V++)
    {
        Graph->G[V].FirstEdge = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        Graph->G[V].FirstEdge->Next = NULL;
        Graph->G[V].FirstEdge->AdjV = V;
        Visited[V] = false;
    }
    for (i = 0; i < Ne; i++)
    {
        scanf("%d %d", &V, &W);
        temp = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        temp->Next = NULL;
        temp->AdjV = W;
        Graph->G[V].FirstEdge->Next = temp;

        temp = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
        temp->Next = NULL;
        temp->AdjV = V;
        Graph->G[W].FirstEdge->Next = temp;
    }
    return Graph;
}

/* 你的代码将被嵌在这里 */

bool IsEdge(LGraph Graph, Vertex V, Vertex W)
{
    PtrToAdjVNode temp;
    temp = Graph->G[V].FirstEdge;
    bool flag = false;
    while (temp)
    {
        if (temp->AdjV == W)
        {
            flag = true;
            break;
        }
        temp = temp->Next;
    }
    return flag;
}

void BFS ( LGraph Graph, Vertex S, void (*Visit)(Vertex) )
{
    Vertex Q[MaxVertexNum];
    int front = -1;
    int rear = -1;
    Vertex V, W;

    Visit(S);
    Visited[S] = true;
    if ((rear + 1) % MaxVertexNum != front)
    {
        Q[++rear] = S;
    }

    while (rear != front)
    {
        V = Q[++front];
        for (W = 0; W < Graph->Nv; W++)
        {
            if (IsEdge(Graph, V, W) && !Visited[W])
            {
                Visited[W] = true;
                Visit(W);
                if ((rear + 1) % MaxVertexNum != front)
                {
                    Q[++rear] = W;
                }
            }
        }
    }

    return;
}
