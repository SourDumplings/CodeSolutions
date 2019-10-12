/*
 @Date    : 2018-03-01 10:24:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1117
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    int A[N];
    for (int i = 0; i != N; ++i) scanf("%d", &A[i]);
    sort(A, A+N, greater<int>());
    int E = N;
    for (int i = 0; i != N; ++i)
    {
        if (A[i] <= i + 1)
        {
            E = i;
            break;
        }
    }
    printf("%d\n", E);
    return 0;
}
