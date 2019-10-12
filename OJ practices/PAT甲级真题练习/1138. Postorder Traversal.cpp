/*
 @Date    : 2018-03-07 15:48:01
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1138
 */

#include <iostream>
#include <cstdio>

using namespace std;

static const int MAXN = 50001;
static int pre[MAXN], in[MAXN], post[MAXN];

void solve(int preB, int preE, int inB, int inE, int postB, int postE)
{
    if (preB == preE) return;
    int root = pre[preB];
    post[postE-1] = root;
    if (preB + 1 == preE) return;
    int lLength = preE - preB - 1;
    for (int i = inB; i != inE; ++i)
    {
        if (in[i] == root)
        {
            lLength = i - inB;
            break;
        }
    }
    solve(preB+1, preB+1+lLength, inB, inB+lLength, postB, postB+lLength);
    solve(preB+1+lLength, preE, inB+lLength+1, inE, postB+lLength, postE-1);
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i != N; ++i) scanf("%d", &pre[i]);
    for (int i = 0; i != N; ++i) scanf("%d", &in[i]);
    solve(0, N, 0, N, 0, N);
    printf("%d\n", post[0]);
    return 0;
}

