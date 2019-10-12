/*
 @Date    : 2017-11-16 11:53:34
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/900290821590183936/problems/928950081667051520
这一道题的难点在于对于那些永远无法插入的数字，何时可以断定它无法插入。
冲突解决方法是平方探测，且只有正数，那么每次冲突后的增量便是：1^2, 2^2, 3^2, 4^2, … , tableSize*2,(tableSize+1)^2, (tableSize+2)^2, …
当达到（tableSize + i）^2 = tableSize*tableSize + 2*tableSize + i^2 时，我们就发现 ，它展开之后对tableSize取余，有影响的只有i，而i已经算过了。所以一旦增量达到tableSize*2，我们便可以断定该数字无法插入哈希表中了。
 */

#include <stdio.h>
#include <math.h>

#define MAXTABLESIZE 20000
#define OCCUPIED 1
#define EMPTY 0
#define ERROR -1

int NextPrime(int N)
{
    if (N <= 2)
    {
        return 2;
    }
    int p = N % 2 ? N : N + 1;
    int i;
    while (p <= MAXTABLESIZE)
    {
        for (i = (int)sqrt(p); i > 2; i--)
        {
            if (p % i == 0)
            {
                break;
            }
        }
        if (i == 2)
        {
            break;
        }
        else
        {
            p += 2;
        }
    }
    return p;
}

int Hash(int TableSize, int key)
{
    return key % TableSize;
}

int first = 1;

int QuadraticProbing(int H[], int TableSize, int Pos)
{
    int i, NewPos;
    for (i = 1; i < TableSize; i++)
    {
        NewPos = (Pos + i * i) % TableSize;
        if (H[NewPos] == EMPTY)
        {
            break;
        }
    }
    if (i == TableSize)
    {
        NewPos = ERROR;
    }
    return NewPos;
}

void InSertAndOutput(int H[], int TableSize, int key)
{
    int Pos = Hash(TableSize, key);
    // printf("Pos = %d\n", Pos);
    if (H[Pos] == OCCUPIED)
    {
        Pos = QuadraticProbing(H, TableSize, Pos);
        // printf("After Probing, Pos = %d\n", Pos);
    }

    if (Pos != ERROR)
    {
        H[Pos] = OCCUPIED;
    }

    if (first)
    {
        first = 0;
    }
    else
    {
        putchar(' ');
    }

    if (Pos != ERROR)
    {
        printf("%d", Pos);
    }
    else
    {
        printf("-");
    }
    return;
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    int TableSize = NextPrime(M);
    // printf("TableSize = %d\n", TableSize);
    int H[TableSize];
    int inputlist[N];
    int i;

    for (i = 0; i < TableSize; i++)
    {
        H[i] = EMPTY;
    }

    for (i = 0; i < N; i++)
    {
        scanf("%d", &inputlist[i]);
    }
    for (i = 0; i < N; i++)
    {
        InSertAndOutput(H, TableSize, inputlist[i]);
    }
    putchar('\n');
    return 0;
}

