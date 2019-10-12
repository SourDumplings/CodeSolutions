/*
 @Date    : 2018-09-08 10:33:12
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/676
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
const int MAXN = 105;
int origin[MAXN], seq[MAXN];
int insertStart = 0;

bool is_insert()
{
    for (int i = 0; i != N - 1; ++i)
    {
        if (seq[i + 1] < seq[i])
        {
            insertStart = i + 1;
            break;
        }
    }
    for (int i = insertStart; i != N; ++i)
    {
        if (seq[i] != origin[i])
            return false;
    }
    return true;
}

void next_insert()
{
    int x = seq[insertStart], i;
    for (i = insertStart - 1; i != -1 && seq[i] > x; --i)
        seq[i + 1] = seq[i];
    seq[i + 1] = x;
    return;
}

void next_heap()
{
    vector<int> res(seq, seq+N);
    sort(res.begin(), res.end());
    int heapEnd = 0;
    for (int i = N - 1; i != -1; --i)
    {
        if (seq[i] != res[i])
        {
            heapEnd = i + 1;
            break;
        }
    }
    swap(seq[0], seq[heapEnd - 1]);
    --heapEnd;
    int x = seq[0] , p, c;
    for (p = 0; ((p << 1) + 1) < heapEnd; p = c)
    {
        c = (p << 1) + 1;
        if (c + 1 < heapEnd && seq[c + 1] > seq[c])
            c += 1;
        if (seq[c] > x)
            seq[p] = seq[c];
        else
            break;
    }
    seq[p] = x;
    return;
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
        scanf("%d", &origin[i]);
    for (int i = 0; i != N; ++i)
        scanf("%d", &seq[i]);
    if (is_insert())
    {
        printf("Insertion Sort\n");
        next_insert();
    }
    else
    {
        printf("Heap Sort\n");
        next_heap();
    }
    int output = 0;
    for (int i = 0; i != N; ++i)
    {
        if (output++)
            putchar(' ');
        printf("%d", seq[i]);
    }
    putchar('\n');
    return 0;
}


