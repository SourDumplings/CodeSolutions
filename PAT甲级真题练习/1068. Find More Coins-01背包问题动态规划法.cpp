/*
 @Date    : 2018-08-30 8:45:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805402305150976
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
const int MAXN = 10005, MAXM = 105;
int f[MAXN][MAXM]; // f[i][j]代表num[i, N)所构成的数之和不超过j的最大值
int num[MAXN];
bool has[MAXN][MAXM]; // has[i][j]代表在选择num[i, N)的数之和不超过j的最大值的过程中是否选择了i

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i != N; ++i)
        scanf("%d", &num[i]);
    sort(num, num+N);
    for (int i = 0; i != N; ++i)
    {
        f[i][0] = 0;
        for (int j = 0; j != M; ++j)
            has[i][j] = false;
    }

    for (int i = N - 1; i != -1; --i)
    {
        for (int j = 1; j != M + 1; ++j)
        {
            if (j < num[i])
                f[i][j] = 0;
            else
            {
                if (i == N - 1)
                {
                    f[i][j] = num[i];
                    has[i][j] = true;
                }
                else if (f[i+1][j-num[i]] + num[i] >= f[i+1][j])
                {
                    // 这里大于等于是为了选出最小序列
                    f[i][j] = f[i+1][j-num[i]] + num[i];
                    has[i][j] = true;
                }
                else
                {
                    f[i][j] = f[i+1][j];
                }
            }
        }
    }
    if (f[0][M] != M)
        printf("No Solution\n");
    else
    {
        vector<int> s;
        int m = M, i = 0;
        while (m > 0)
        {
            for (; i != N && !has[i][m]; ++i);
            if (i == N) break;
            m -= num[i];
            s.push_back(num[i]);
            ++i;
        }
        int output = 0;
        for (int i : s)
        {
            if (output++)
                putchar(' ');
            printf("%d", i);
        }
        putchar('\n');
    }
    return 0;
}
