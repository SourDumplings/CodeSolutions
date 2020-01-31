/*
 * @Author: SourDumplings
 * @Date: 2019-09-23 09:59:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://pintia.cn/problem-sets/16/problems/707
 */

const int NO_WAY = -1;

int find_min_dist(int dist[], int n, bool visited[])
{
    int v = -1, minD = INFINITY;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && dist[i] != NO_WAY && dist[i] < minD)
        {
            minD = dist[i];
            v = i;
        }
    }
    return v;
}

void ShortestDist(MGraph Graph, int dist[], Vertex S)
{
    int n = Graph->Nv;
    bool visited[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dist[i] = NO_WAY;
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
        for (int w = 0; w < n; ++w)
        {
            int d = (Graph->G)[v][w];
            if (d != NO_WAY && d != INFINITY && !visited[w] && (dist[v] + d < dist[w] || dist[w] == NO_WAY))
            {
                dist[w] = dist[v] + d;
            }
        }
    }
}