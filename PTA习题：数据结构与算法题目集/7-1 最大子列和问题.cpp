/*
 @Date    : 2018-03-10 14:37:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/709
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int A[N];
    int thisSum = 0, maxSum = 0;
    for (int i = 0; i != N; ++i) scanf("%d", &A[i]);
    for (int i = 0; i < N; ++i)
    {
        thisSum += A[i];
        if (thisSum < 0)
            thisSum = 0;
        if (thisSum > maxSum)
            maxSum = thisSum;
    }
    printf("%d\n", maxSum);
    return 0;
}

