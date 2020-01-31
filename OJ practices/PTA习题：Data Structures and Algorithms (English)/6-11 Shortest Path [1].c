/*
 * @Author: SourDumplings
 * @Date: 2019-09-23 09:36:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://pintia.cn/problem-sets/16/problems/706
 */

const int MAXD = 99999;
const int NO_WAY = -1;

int find_min_dist(int dist[], int n, bool visited[])
{
    int v = -1, minD = MAXD;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] < minD && dist[i] != NO_WAY)
        {
            v = i;
            minD = dist[i];
        }
    }
    return v;
}

void ShortestDist(LGraph Graph, int dist[], Vertex S)
{
    int n = Graph->Nv;
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        dist[i] = NO_WAY;
        visited[i] = false;
    }
    dist[S] = 0;

    while (true)
    {
        int v = find_min_dist(dist, n, visited);
        if (v == -1)
        {
            break;
        }

        visited[v] = true;
        PtrToAdjVNode L = (Graph->G)[v].FirstEdge;
        while (L)
        {
            int w = L->AdjV;
            if (dist[v] + 1 < dist[w] || dist[w] == NO_WAY)
            {
                dist[w] = dist[v] + 1;
            }
            L = L->Next;
        }
    }
}