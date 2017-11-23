/*
 @Date    : 2017-11-14 18:11:23
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/900290821590183936/problems/928950008090570752
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define KEYLENGTH 11 // 关键字字符串的最大长度

typedef char ElementType[KEYLENGTH+1];
typedef int Index; // 散列地址类型

typedef struct LNode *List;
typedef struct LNode *Position;
struct LNode
{
    ElementType Data;
    Position Next;
    int Count; // 该电话号码的出现的次数
};

typedef struct TblNode *HashTable;
struct TblNode
{
    // 散列表结点的定义
    int TableSize; // 表的最大长度
    List *Heads; // 指向链表头结点的指针数组
};

#define MAXTABLESIZE 1000000
int NextPrime(int N)
{
    // 获取大于N且不超过MAXTABLESIZE的最小素数
    int i, p = (N % 2) ? N + 2 : N + 1; // 从大于N的下一个奇数开始
    while (p <= MAXTABLESIZE)
    {
        for (i = 3; i <= (int)sqrt(p); i++)
        {
            if (p % i == 0)
            {
                // p不是素数
                break;
            }
        }
        if (i > (int)sqrt(p))
        {
            // 循环正常结束，p是素数
            break;
        }
        else
        {
            p += 2;
        }
    }
    return p;
}

HashTable CreateTable(int TableSize)
{
    HashTable H;
    int i;
    H = (HashTable)malloc(sizeof(struct TblNode));
    H->TableSize = NextPrime(TableSize);
    H->Heads = (List *)malloc(H->TableSize * sizeof(List));
    for (i = 0; i < H->TableSize; i++)
    {
        H->Heads[i] = (List)malloc(sizeof(struct LNode));
        H->Heads[i]->Data[0] = '\0';
        H->Heads[i]->Next = NULL;
        H->Heads[i]->Count = 0;
    }
    return H;
}

int Hash(int Key, int p)
{
    // 除留取余法散列函数
    return Key % p;
}

#define MAXD 5 // 参与散列映射计算的字符个数

Position Find(HashTable H, ElementType Key)
{
    Position P;
    Index Pos;
    // 初始散列的位置
    Pos = Hash(atoi(Key+KEYLENGTH-MAXD), H->TableSize);
    P = H->Heads[Pos]->Next; // 从该链表的第一个结点开始
    // 当未到表尾，并且Key未找到时
    while (P && strcmp(P->Data, Key))
    {
        P = P->Next;
    }
    return P;
}

int Insert(HashTable H, ElementType Key)
{
    Position P, NewCell;
    Index Pos;
    P = Find(H, Key);
    if (!P)
    {
        NewCell = (Position)malloc(sizeof(struct LNode));
        strcpy(NewCell->Data, Key);
        NewCell->Count = 1;
        // 初始散列位置
        Pos = Hash(atoi(Key+KEYLENGTH-MAXD), H->TableSize);
        // 将NewCell插入为H->Heads[Pos]链表的第一个结点
        NewCell->Next = H->Heads[Pos]->Next;
        H->Heads[Pos]->Next = NewCell;
        return 1;
    }
    else
    {
        // 关键词已经存在
        // printf("关键词已经存在\n");
        P->Count++;
        return 0;
    }
}

void ScanAndOutput(HashTable H)
{
    int i, MaxCnt = 0, Pcnt = 0;
    ElementType MinPhone;
    List P;
    MinPhone[0] = '\0';
    for (i = 0; i < H->TableSize; i++)
    {
        P = H->Heads[i]->Next;
        while (P)
        {
            if (P->Count > MaxCnt)
            {
                MaxCnt = P->Count;
                strcpy(MinPhone, P->Data);
                Pcnt = 1;
            }
            else if (P->Count == MaxCnt)
            {
                Pcnt++;
                if (strcmp(MinPhone, P->Data) > 0)
                {
                    strcpy(MinPhone, P->Data);
                }
            }
            P = P->Next;
        }
    }
    printf("%s %d", MinPhone, MaxCnt);
    if (Pcnt > 1)
    {
        printf(" %d", Pcnt);
    }
    putchar('\n');
    return;
}

void DestroyTable(HashTable H)
{
    int N = H->TableSize;
    int i;
    List front, temp;
    for (i = 0; i < N; i++)
    {
        front = H->Heads[i];
        while (front)
        {
            temp = front->Next;
            free(front);
            front = temp;
        }
    }
    free(H);
    return;
}

int main()
{
    int N, i;
    ElementType Key;
    HashTable H;
    // 创建散列表
    scanf("%d", &N);
    H = CreateTable(N*2);
    // 读入号码插入表中
    for (i = 0; i < N; i++)
    {
        scanf("%s", Key);
        Insert(H, Key);
        scanf("%s", Key);
        Insert(H, Key);
    }
    // 扫描表输出狂人
    ScanAndOutput(H);
    DestroyTable(H);
    return 0;
}

