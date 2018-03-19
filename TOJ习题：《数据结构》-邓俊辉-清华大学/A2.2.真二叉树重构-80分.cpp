/*
 @Date    : 2018-02-08 09:28:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1146
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

const int maxn = 4000001;

void solve(int pre[], int preB, int preE, int post[],
    int postB, int postE, int in[], int inB, int inE)
{
    if (preE <= preB) return;
    else if (preB == preE - 1)
    {
            in[inB] = pre[preB];
            return;
    }
    int root = pre[preB];
    int lRootInPostPos;
    for (int i = postB; i != postE; ++i)
    {
        if (post[i] == pre[preB+1])
        {
            lRootInPostPos = i;
            break;
        }
    }
    int lLength = (lRootInPostPos-postB)+1;
    in[inB+lLength] = root;
    solve(pre, preB+1, preB+lLength+1, post, postB, postB+lLength, in, inB, inB+lLength);
    solve(pre, preB+lLength+1, preE, post, postB+lLength, postE-1, in, inB+lLength+1, inE);
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int pre[maxn], post[maxn], in[maxn];
    for (int i = 0; i != n; ++i)
        scanf("%d", &pre[i]);
    for (int i = 0; i != n; ++i)
        scanf("%d", &post[i]);
    solve(pre, 0, n, post, 0, n, in, 0, n);
    int output = 0;
    for (auto i : in)
    {
        if (output++)
            putchar(' ');
        printf("%d", i);
    }
    putchar('\n');
    return 0;
}
