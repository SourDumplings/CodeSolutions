/*
 @Date    : 2018-02-05 18:52:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1145
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int SZ = 1<<20;  //快速io
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

const int maxn = 1600001;
// const int maxn = 1600;

int S[maxn];
int top = -1;
int B[maxn];
char order[2*maxn];
int o = 0;

int main(int argc, char const *argv[])
{
    int n, m;
    scanf("%d %d", &n, &m);
    int topA = 1;
    bool judge = true;
    for (int i = 0; i != n; ++i)
        scanf("%d", &B[i]);
    for (int i = 0; i != n;)
    {
        if (top != -1 && S[top] == B[i])
        {
            order[o++] = 'o';
            --top;
            ++i;
        }
        else
        {
            while (topA <= n && top < m - 1 && (top == -1 || S[top] != B[i]))
            {
                order[o++] = 'u';
                S[++top] = topA++;
            }
            if ((topA > n || top >= m - 1) && S[top] != B[i])
                judge = false;
        }
        if (!judge)
            break;
    }

    if (judge)
    {
        for (int i = 0; i != o; ++i)
        {
            switch (order[i])
            {
                case 'o' : printf("pop\n"); break;
                case 'u' : printf("push\n"); break;
            }
        }
    }
    else
        printf("No\n");

    return 0;
}
