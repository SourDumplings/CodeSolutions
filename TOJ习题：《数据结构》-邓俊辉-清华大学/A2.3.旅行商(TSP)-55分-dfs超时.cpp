/*
 @Date    : 2018-02-13 15:20:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1147
 */

#include <iostream>
#include <cstdio>

using namespace std;

static int n, m;
const int MAXN = 1000001;
static int inDegree[MAXN];

const int SZ = 1 << 20; //快速io
struct fastio {
    char inbuf[SZ];
    char outbuf[SZ];
    fastio() {
        setvbuf(stdin, inbuf, _IOFBF, SZ);
        setvbuf(stdout, outbuf, _IOFBF, SZ);
    }
} io;

struct VillageNode
{
    int v;
    VillageNode *next = nullptr;
};

struct VillageList
{
    VillageNode *first = nullptr;
};

struct LGraph
{
    VillageList G[MAXN];
    void insert_edge(int, int);
    ~LGraph()
    {
        for (int i = 0; i != n; ++i)
        {
            auto nextNode = G[i].first;
            for (auto now = G[i].first; now; now = nextNode)
            {
                nextNode = now->next;
                delete now;
            }
        }
    }
};

void LGraph::insert_edge(int u, int v)
{
    VillageNode *newVillage = new VillageNode;
    newVillage->v = v;
    newVillage->next = G[u].first;
    G[u].first = newVillage;
    ++inDegree[v];
    return;
}

bool visited[MAXN];

void initialize_visit()
{
    for (int i = 0; i != n; ++i)
        visited[i] = false;
    return;
}

int one_dfs(LGraph &Graph, int start)
{
    visited[start] = true;
    int maxVillageNum = 0;
    for (auto W = Graph.G[start].first; W; W = W->next)
    {
        int villageNum = one_dfs(Graph, W->v);
        if (villageNum > maxVillageNum)
            maxVillageNum = villageNum;
    }
    return maxVillageNum + 1;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    int u, v;
    LGraph Graph;
    for (int i = 0; i != n; ++i)
        inDegree[i] = 0;
    for (int i = 0; i != m; ++i)
    {
        scanf("%d %d", &u, &v);
        Graph.insert_edge(u - 1, v - 1);
    }
    int maxVillageNum = 0;
    for (int i = 0; i != n; ++i)
    {
        if (inDegree[i] == 0)
        {
            initialize_visit();
            int VillageNums = one_dfs(Graph, i);
            if (VillageNums > maxVillageNum)
                maxVillageNum = VillageNums;
        }
    }
    printf("%d\n", maxVillageNum);

    return 0;
}
