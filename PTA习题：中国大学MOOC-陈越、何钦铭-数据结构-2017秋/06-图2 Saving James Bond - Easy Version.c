#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100

typedef struct GRAPH *Graph;
struct GRAPH
{
    int *x;
    int *y;
};

int visited[MAXN] = {0};
int N, D;
int answer = 0;

void InputPosition(Graph G, int N)
{
    int i;
    for (i = 1; i <= N; i++)
    {
        scanf("%d %d", &G->x[i], &G->y[i]);
    }
    return;
}

int Jump(Graph G, int v, int w)
{
    double d;
    d = sqrt(pow((G->x[v] - G->x[w]), 2) + pow((G->y[v] - G->y[w]), 2));
    if (!v)
    {
            int first_D = D + 7.5;
            if (first_D >= d)
            {
                return 1;
            }
            else
            {
                return 0;
            }
    }
    if (d <= D)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Escape(Graph G, int v)
{
    int x = G->x[v];
    int y = G->y[v];
    if (!v && D >= 42.5)
    {
        return 1;
    }
    if ((50 - x) <= D || (50 - y) <= D
        || (x + 50) <= D || (y + 50) <= D)
        return 1;
    else
        return 0;
}

void DFS(Graph G, int v)
{
    int w;

    if (answer)
    {
        return;
    }

    if (Escape(G, v))
        {
            answer = 1;
            return;
        }

    for (w = 1; w <= N; w++)
    {
        if (visited[w])
        {
            continue;
        }
        if (Jump(G, v, w))
        {
            visited[w] = 1;
            DFS(G, w);
        }
    }
    return;
}

int main()
{
    Graph G;
    int i;

    scanf("%d %d", &N, &D);

    G = (Graph)malloc(sizeof(struct GRAPH));
    G->x = (int *)malloc((N+1) * sizeof(int));
    G->y = (int *)malloc((N+1) * sizeof(int));
    G->x[0] = G->y[0] = 0;

    InputPosition(G, N);

    if (Escape(G, 0))
    {
        answer = 1;
    }
    else
    {
        for (i = 1; i <= N; i++)
        {
            if (answer)
            {
                break;
            }
            if (visited[i])
            {
                continue;
            }
            if (Jump(G, 0, i))
            {
                visited[i] = 1;
                DFS(G, i);
            }
        }
    }

    if (answer)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}
