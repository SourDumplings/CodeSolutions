/*
 @Date    : 2018-02-06 20:14:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1068
我们设f(i,j)表示从前i个硬币中选出的面值不大于j的最大的面值和，
设硬币序列中第i个硬币的面值为c[i]，则f(i,j)的计算可以分为两种情况递推考虑：

每个硬币都有放入和不放入两种情况。

①放入第i个硬币，即f(i-1,j-c[i]) + c[i]。

②不放入第i个硬币，即f(i-1,j)。

要保证面值最大，应该选择二者中的较大者.
因此我们只要从i=1~N，分别解决j=1~M的问题，便可以得到不超过M的最大面值，通过判断f(N,M)，
如果它=M，说明能够找到这样的序列，否则说明找不到，因为它是不超过M的，
从所有硬币中能组合出的最大的和。

【如何使序列最小】

接下来我们解决序列最小的问题，我们这样考虑，每当加入一个c[i]，
序列中就会多一个元素，如果我们让硬币按照降序排列，这样每一次加入c[i]，
都相当于加入了一个更小的序列头，例如现在的序列是{5,3,2}，因为是降序，c[i]≤2，
因此只要加入c[i]，序列会变成{5,3,2,c[i]}，这个序列必定变小，
因此我们应该记录下所有加入c[i]时的下标，最后根据这些下标回溯，即可得到最小的序列。
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 10001;
const int MAXM = 101;
int f[MAXN][MAXM];
bool has[MAXN][MAXM];

bool solve(int c[], int N, int M)
{
    int sec; // 表示放入c[i]之后的值
    memset(f, 0, sizeof(int)*MAXN * MAXM);
    memset(has, false, sizeof(bool)*MAXN * MAXM);
    for (int i = 1; i != N + 1; ++i)
    {
        for (int j = 1; j != M + 1; ++j)
        {
            if (c[i] > j) sec = 0;
            else sec = f[i - 1][j - c[i]] + c[i];
            if (sec >= f[i - 1][j])
            {
                // 注意是大于等于，这样可以保证选的是最小序列
                f[i][j] = sec;
                has[i][j] = true;
            }
            else
                f[i][j] = f[i - 1][j];
        }
    }
    return f[N][M] == M;
}

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    int c[MAXN];
    int solution[MAXN], s = 0;
    c[0] = 0;
    for (int i = 1; i != N + 1; ++i)
        scanf("%d", &c[i]);
    sort(c + 1, c + N + 1, [] (const int c1, const int c2) { return c1 > c2; });
    if (solve(c, N, M))
    {
        while (M)
        {
            while (!has[N][M])
                --N;
            solution[s++] = c[N];
            M -= c[N];
            --N;
        }
        int output = 0;
        for (int i = 0; i != s; ++i)
        {
            if (output++)
                putchar(' ');
            printf("%d", solution[i]);
        }
        putchar('\n');
    }
    else
        printf("No Solution\n");
    return 0;
}
