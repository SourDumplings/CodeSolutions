/*
 @Date    : 2018-02-16 12:36:30
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1085
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, p;
    scanf("%d %d", &N, &p);
    long long num[N];
    for (int i = 0; i != N; ++i)
        scanf("%lld", &num[i]);
    sort(num, num+N);
    int i, j;
    int f[N][N];
    int temp;
    // 初始化目标函数
    for (i = 0; i != N; ++i)
    {
        for (j = 0; j != N; ++j)
            f[i][j] = 0;
    }
    f[0][0] = f[N-1][N-1] = 1;


    // // 动态规划求解
    for (i = N - 2; i != -1; --i)
    {
        for (j = i + 1; j != N; ++j)
        {
            temp = max(f[i+1][j], f[i][j-1]);
            if (num[j] <= num[i] * p)
                f[i][j] = temp + 1;
            else
                f[i][j] = temp;
        }
    }

    // for (i = 0; i != N; ++i)
    // {
    //     for (j = 0; j != N; ++j)
    //         printf("%d ", f[i][j]);
    //     putchar('\n');
    // }

    int max = 0;
    for (i = 0; i != N; ++i)
    {
        temp = *max_element(f[i], f[i]+N);
        if (temp > max)
            max = temp;
    }
    printf("%d\n", max);

    return 0;
}
