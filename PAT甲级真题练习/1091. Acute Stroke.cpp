/*
 @Date    : 2018-02-18 10:53:15
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1091
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

static const int MAXM = 1300, MAXN = 131, MAXL = 61;
static const int X[6] = {1, 0, 0, -1, 0, 0};
static const int Y[6] = {0, 1, 0, 0, -1, 0};
static const int Z[6] = {0, 0, 1, 0, 0, -1};
static int G[MAXL][MAXM][MAXN];
static bool visited[MAXL][MAXM][MAXN];
static int M, N, L, T;

struct Pixel { int z, x, y; Pixel(int z_, int x_, int y_): z(z_), x(x_), y(y_) {} };

bool is_center(int z, int x, int y)
{
    return !visited[z][x][y] && G[z][x][y] == 1;
}

bool judge(int z, int x, int y)
{
    return (z < L && z > -1) && (x < M && x > -1) && (y < N && y > -1) &&
    is_center(z, x, y);
}

int bfs(int z, int x, int y)
{
    queue<Pixel> q;
    Pixel center(z, x, y);
    q.push(center);
    visited[z][x][y] = true;
    int v = 0;
    while (!q.empty())
    {
        Pixel c = q.front();
        q.pop();
        ++v;
        for (int i = 0; i != 6; ++i)
        {
            int next_z = c.z + Z[i];
            int next_x = c.x + X[i];
            int next_y = c.y + Y[i];
            if (judge(next_z, next_x, next_y))
            {
                visited[next_z][next_x][next_y] = true;
                q.push(Pixel(next_z, next_x, next_y));
            }
        }
    }
    if (v >= T)
        return v;
    else
        return 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d", &M, &N, &L, &T);
    int res = 0;
    for (int i = 0; i != L; ++i)
        for (int j = 0; j != M; ++j)
            for (int k = 0; k != N; ++k)
            {
                visited[i][j][k] = false;
                scanf("%d", &G[i][j][k]);
            }
    for (int i = 0; i != L; ++i)
        for (int j = 0; j != M; ++j)
            for (int k = 0; k != N; ++k)
                if (is_center(i, j, k))
                    res += bfs(i, j, k);
    printf("%d\n", res);
    return 0;
}
