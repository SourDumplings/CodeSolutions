/*
 @Date    : 2018-03-15 16:30:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/889
题目有坑，如果要填入的数字已经出现过了，则直接输出第一次的散列位置
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

static int N, P;
static const int MAXN = 2002;
static bool hashTable[MAXN];
static int posData[MAXN];

static int output = 0;

void my_insert(int num)
{
    int h = num % P;
    int p = h;
    if (posData[num] == -1)
    {
        for (; hashTable[p]; p = (p + 1) % P);
        posData[num] = p;
        hashTable[p] = true;
    }
    else
        p = posData[num];
    if (output++)
    {
        putchar(' ');
    }
    printf("%d", p);
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &P);
    fill(hashTable, hashTable+P, false);
    fill(posData, posData+MAXN, -1);
    for (unsigned i = 0; i < N; ++i)
    {
        int num;
        scanf("%d", &num);
        my_insert(num);
    }
    putchar('\n');
    return 0;
}

