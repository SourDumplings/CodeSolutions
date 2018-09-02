/*
 @Date    : 2018-09-02 20:19:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805375457411072
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int N, M, L, T;
const int MAXM = 1287, MAXN = 129, MAXL = 61;
bool G[MAXM][MAXN][MAXL], checked[MAXM][MAXN][MAXL];
const int DX[6] = {1, 0, 0, -1, 0, 0}, DY[6] = {0, 1, 0, 0, -1, 0}, DZ[6] = {0, 0, 1, 0, 0, -1};
int res = 0;

struct Pixel
{
    int x, y, z;
    Pixel(int i, int j, int k): x(i), y(j), z(k) {}
};

Pixel get_adj(const Pixel &c, int n)
{
    int x = c.x + DX[n], y = c.y + DY[n], z = c.z + DZ[n];
    if (x < 0 || y < 0 || z < 0 || x > M - 1 || y > N - 1 || z > L - 1)
        return Pixel(-1, -1, -1);
    else
        return Pixel(x, y, z);
}

int bfs(int i, int j, int k)
{
    queue<Pixel> Q;
    Q.push(Pixel(i, j, k));
    checked[i][j][k] = true;
    int ret = 0;
    while (!Q.empty())
    {
        Pixel c = Q.front(); Q.pop();
        ++ret;
        for (int n = 0; n != 6; ++n)
        {
            Pixel p = get_adj(c, n);
            if (p.x >= 0 && !checked[p.x][p.y][p.z] && G[p.x][p.y][p.z])
            {
                Q.push(p);
                checked[p.x][p.y][p.z] = true;
            }
        }
    }
    return ret;
}

int main()
{
    scanf("%d %d %d %d", &M, &N, &L, &T);
    for (int k = 0; k != L; ++k)
    {
        for (int i = 0; i != M; ++i)
        {
            for (int j = 0; j != N; ++j)
            {
                int f;
                scanf("%d", &f);
                G[i][j][k] = (f == 1);
                checked[i][j][k] = false;
            }
        }
    }
    for (int k = 0; k != L; ++k)
    {
        for (int i = 0; i != M; ++i)
        {
            for (int j = 0; j != N; ++j)
            {
                if (!checked[i][j][k] && G[i][j][k])
                {
                    int dv = bfs(i, j, k);
                    res += (dv >= T ? dv : 0);
                }
            }
        }
    }
    printf("%d\n", res);
    return 0;
}
