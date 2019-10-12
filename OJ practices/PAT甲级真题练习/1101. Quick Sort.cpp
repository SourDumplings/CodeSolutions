/*
 @Date    : 2018-02-21 21:12:22
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1101
利用动态规划思想，记录每个点之前的最大值和每个点之后的最小值。
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

static int N;

int main(int argc, char const *argv[])
{
    // 读入数据
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i != N; ++i)
        scanf("%d", &A[i]);
    // 动态规划
    int maxValueBefore[N], minValueAfter[N];
    maxValueBefore[0] = A[0];
    minValueAfter[N-1] = A[N-1];
    for (int i = 1; i != N; ++i)
    {
        if (A[i-1] > maxValueBefore[i-1])
            maxValueBefore[i] = A[i-1];
        else
            maxValueBefore[i] = maxValueBefore[i-1];
    }
    for (int i = N - 2; i != -1; --i)
    {
        if (A[i+1] < minValueAfter[i+1])
            minValueAfter[i] = A[i+1];
        else
            minValueAfter[i] = minValueAfter[i+1];
    }
    // 甄别pivot
    vector<int> pivot;
    for (int i = 0; i != N; ++i)
    {
        if (A[i] >= maxValueBefore[i] && A[i] <= minValueAfter[i])
            pivot.push_back(A[i]);
    }
    // 输出pivot
    printf("%d\n", pivot.size());
    int output = 0;
    for (int i : pivot)
    {
        if (output++)
            putchar(' ');
        printf("%d", i);
    }
    putchar('\n');
    return 0;
}
