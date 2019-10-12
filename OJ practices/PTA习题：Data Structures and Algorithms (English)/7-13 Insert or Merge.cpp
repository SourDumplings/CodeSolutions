/*
 @Date    : 2018-09-08 09:32:01
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/675
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

void my_merge(int b1, int e1, int b2, int e2)
{
    int i1 = 0, i2 = 0, n = e1 - b1, i = b1;
    vector<int> seq1(seq+b1, seq+e1), seq2(seq+b2, seq+e2);
    while (i1 < n && i2 < n)
    {
        if (seq1[i1] <= seq2[i2])
        {
            seq[i++] = seq1[i1++];
        }
        else
        {
            seq[i++] = seq2[i2++];
        }
    }
    while (i1 < n)
    {
        seq[i++] = seq1[i1++];
    }
    while (i2 < n)
    {
        seq[i++] = seq2[i2++];
    }
    return;
}

void next_merge()
{
    int tryT;
    for (tryT = 2; tryT <= N; tryT <<= 1)
    {
        bool flag = true;
        for (int i = 0; i < N; i += tryT)
        {
            for (int j = i; j != i + tryT - 1 && j < N - 1; ++j)
            {
                if (seq[j] > seq[j + 1])
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
                break;
        }
        if (!flag)
        {
            tryT >>= 1;
            break;
        }
    }
    int T = tryT << 1;
    if (T <= N)
    {
        int r = N % T;
        for (int i = 0; i < N - r; i += T)
        {
            my_merge(i, i + tryT, i + tryT, i + T);
        }
        if (r > 0)
        {
            sort(seq + N - r, seq + N);
        }
    }
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
        printf("Merge Sort\n");
        next_merge();
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

