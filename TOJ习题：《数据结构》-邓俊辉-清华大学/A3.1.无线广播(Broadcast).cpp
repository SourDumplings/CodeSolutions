/*
 @Date    : 2018-02-23 22:23:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1148
 */

#include <iostream>
#include <cstdio>

using namespace std;

static const int MAXN = 10001;
static bool G[MAXN][MAXN];
static int N, M;
static bool isInQ[MAXN];
static bool checked[MAXN];

class Queue
{
public:
    int front = 0, back = 0;
    bool empty() { return front == back; }
    void push(int i)
    {
        int temp = back;
        back = (back + 1) % MAXN;
        data[temp] = i;
        return;
    }
    int pop()
    {
        int temp = front;
        front = (front + 1) % MAXN;
        return data[temp];
    }
private:
    int data[MAXN];
};


bool BFS(int N)
{
    Queue Q;
    Q.push(0);
    isInQ[0] = true;
    int v, w;
    while (!Q.empty())
    {
        v = Q.pop();
        isInQ[v] = false;
        checked[v] = true;
        for (w = 0; w != N; ++w)
        {
            if (!checked[w] && G[v][w])
            {
                if (!isInQ[w])
                {
                    isInQ[w] = true;
                    Q.push(w);
                }
                else
                    return false;
            }
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i != N; ++i)
    {
        isInQ[i] = checked[i] = false;
        for (int j = 0; j != N; ++j)
            G[i][j] = false;
    }
    int v, w;
    for (int i = 0 ; i != M; ++i)
    {
        scanf("%d %d", &v, &w);
        G[v-1][w-1] = G[w-1][v-1] = true;
    }
    bool ok = true;
    ok = BFS(N);
    if (ok) printf("1\n");
    else printf("-1\n");
    return 0;
}
