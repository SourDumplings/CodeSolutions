/*
 @Date    : 2018-02-23 17:24:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1105
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

enum Direction {RIGHT, DOWN, LEFT, UP};

static const int MAXN = 101;
static int res[MAXN][MAXN];

void output(int m, int n)
{
    int output = 0;
    for (int i = 0; i != m; ++i)
    {
        output = 0;
        for (int j = 0; j != n; ++j)
        {
            if (output++) putchar(' ');
            printf("%d", res[i][j]);
        }
        putchar('\n');
    }
    return;
}

void fill_array(int m, int n, int A[], int index)
{
    static Direction d = RIGHT;
    static int pos_i = 0, pos_j = 0;
    static int max_i = m - 1, max_j = n - 1;
    static int min_i = 0, min_j = 0;
    res[pos_i][pos_j] = A[index];
    // printf("A[%d] = %d\n", index, A[index]);
    // output(m, n);
    switch (d)
    {
        case RIGHT:
        {
            if (pos_j == max_j)
            {
                d = DOWN;
                ++pos_i;
                ++min_i;
            }
            else ++pos_j;
            break;
        }
        case DOWN:
        {
            if (pos_i == max_i)
            {
                d = LEFT;
                --pos_j;
                --max_j;
            }
            else ++pos_i;
            break;
        }
        case LEFT:
        {
            if (pos_j == min_j)
            {
                d = UP;
                --pos_i;
                --max_i;
            }
            else --pos_j;
            break;
        }
        case UP:
        {
            if (pos_i == min_i)
            {
                d = RIGHT;
                ++pos_j;
                ++min_j;
            }
            else --pos_i;
            break;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int m, n;
    for (m = 1; m != N + 1; ++m)
    {
        if (N % m == 0 && N / m <= m)
        {
            n = N / m;
            break;
        }
    }
    int A[N];
    for (int i = 0; i != N; ++i)
        scanf("%d", &A[i]);
    sort(A, A+N, [] (const int &i1, const int &i2) { return i1 > i2; });
    for (int i = 0; i != N; ++i)
        fill_array(m, n, A, i);
    output(m, n);
    return 0;
}
