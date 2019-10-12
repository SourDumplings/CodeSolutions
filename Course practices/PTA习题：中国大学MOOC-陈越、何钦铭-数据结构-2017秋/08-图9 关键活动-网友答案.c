#include <stdio.h>

#define MAXINT 0x7fffffff
#define Max 101

int Graph[Max][Max], Indegree[Max], Outdegree[Max], Earliest[Max], Latest[Max];

int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

int Earliest_Time(int N);
void Latest_Time(int N, int res);

int main(int argc, char const *argv[])
{
    // freopen("test.txt", "r", stdin);
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= N; j++){
            Graph[i][j] = -1;
        }
        Indegree[i] = 0;
        Outdegree[i] = 0;
        Earliest[i] = 0;
        Latest[i] = MAXINT;
    }
    int s, e, c;
    for (int i = 0; i < M; i++){
        scanf("%d %d %d", &s, &e, &c);
        Graph[s][e] = c;
        Outdegree[s]++;
        Indegree[e]++;
    }
    int res = Earliest_Time(N);
    Latest_Time(N, res);
    if (res == -1)
        printf("0");
    else{
        printf("%d\n", res);
        for (int i = 1; i <= N; i++){
            if (Earliest[i] != Latest[i])
                continue;
            for (int j = N; j >= 1; j--){
                if (Graph[i][j] >= 0 && Earliest[j] == Latest[j] && (Latest[j] - Earliest[i] == Graph[i][j]))
                    printf("%d->%d\n", i, j);
            }
        }
    }
    return 0;
}

int Earliest_Time(int N)
{
    int queue[N+1], front = 0, rear = 0;
    for (int i = 1; i <= N; i++){
        if (Indegree[i] == 0){
            queue[rear++] = i;
            Indegree[i]--;
        }
    }
    int cnt = 0, v;
    while (rear - front){
        v = queue[front++];
        cnt++;
        for (int i = 1; i <= N; i++){
            if (Graph[v][i] >= 0){
                Indegree[i]--;
                Earliest[i] = max(Earliest[i], Earliest[v] + Graph[v][i]);
            }
            if (Indegree[i] == 0){
                queue[rear++] = i;
                Indegree[i]--;
            }
        }
    }
    int res = 0;
    if (cnt != N)
        return -1;
    else {
        for (int i = 1; i <= N; i++){
            if (Outdegree[i] == 0)
                res = max(res, Earliest[i]);
        }
        return res; // 即返回结束工程节点中最早开始时间的最大值，即为完成整个项目的所需时间
    }
}

void Latest_Time(int N, int res)
{
    int queue[N+1], front = 0, rear = 0;
    for (int i = 1; i <= N; i++){
        if (Outdegree[i] == 0){
            queue[rear++] = i;
            Latest[i] = res;
            // Outdegree[i]--;
        }
    }
    int v;
    while (rear - front){
        v = queue[front++];
        for (int i = N; i >= 1; i--){
            if (Graph[i][v] >= 0){
                Outdegree[i]--;
                Latest[i] = min(Latest[i], Latest[v] - Graph[i][v]);
                if (Outdegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }
}
