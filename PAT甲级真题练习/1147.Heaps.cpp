/*
 @Date    : 2018-08-08 21:11:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805342821531648
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1005;
int M, N;
vector<int> seq;

bool check_max_heap()
{
    for (int i = 1; i << 1 <= N; ++i)
    {
        if (seq[i] < seq[i<<1] || (((i<<1)+1 <= N) && seq[i] < seq[(i<<1)+1]))
        {
            return false;
        }
    }
    return true;
}

bool check_min_heap()
{
    for (int i = 1; i << 1 <= N; ++i)
    {
        if (seq[i] > seq[i<<1] || (((i<<1)+1 <= N) && seq[i] > seq[(i<<1)+1]))
        {
            return false;
        }
    }
    return true;
}

int output;
void post_traversal(int i)
{
    if (i << 1 <= N)
    {
        post_traversal(i << 1);
        if ((i << 1) + 1 <= N)
        {
            post_traversal((i << 1) + 1);
        }
    }
    if (output++)
    {
        putchar(' ');
    }
    printf("%d", seq[i]);
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &M, &N);
    seq.resize(N+1);
    for (int i = 0; i < M; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            int num;
            scanf("%d", &num);
            seq[j] = num;
        }

        if (check_max_heap())
        {
            printf("Max Heap\n");
        }
        else if (check_min_heap())
        {
            printf("Min Heap\n");
        }
        else
            printf("Not Heap\n");

        output = 0;
        post_traversal(1);
        putchar('\n');

    }
    return 0;
}

