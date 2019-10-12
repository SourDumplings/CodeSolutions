/*
 @Date    : 2018-02-06 20:14:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1068
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

bool find_chages(const int A[], int start, int N, int amountRes, int solution[], int &s)
{
    // printf("start = %d\n", start);
    if (amountRes == 0) return true;
    else if (start == N - 1 || A[start+1] > amountRes) return false;
    bool judge = true;
    for (int i = start + 1; i != N; ++i)
    {
        solution[s++] = A[i];
        judge = find_chages(A, i, N, amountRes-A[i], solution, s);
        if (judge)
            break;
        else
            --s;
    }
    return judge;
}

int main(int argc, char const *argv[])
{
    const int maxn = 10001;
    int N, M;
    scanf("%d %d", &N, &M);
    int A[maxn];
    int solution[maxn], s = 0;
    for (int i = 0; i != N; ++i)
        scanf("%d", &A[i]);
    sort(A, A+N);
    if (find_chages(A, -1, N, M, solution, s))
    {
        int output = 0;
        for (int i = 0; i != s; ++i)
        {
            if (output++)
                putchar(' ');
            printf("%d", solution[i]);
        }
        printf("\n");
    }
    else
        printf("No Solution\n");
    return 0;
}
