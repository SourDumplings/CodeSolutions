/*
 @Date    : 2017-12-03 14:04:38
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1032
这题最坑的地方是有可能出现L2的开始地址就是-1，直接输出-1即可
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXN 100001

typedef struct LNODE *Lnode;
struct LNODE
{
    int this_id;
    int next_id;
    int belongL1;
};

Lnode Ldata[MAXN];
int HashTable[MAXN]; // 存储this_id在Ldata中的下标


int Hash(int key, int tablesize)
{
    return key % tablesize;
}

void Insert(int key, int value)
{
    int h = Hash(key, MAXN);
    int i;
    for (i = h; i < MAXN && HashTable[i]; i = (i + 1) % MAXN);
    HashTable[i] = value;
    return;
}

int Find(int key)
{
    int h = Hash(key, MAXN);
    int i;
    int count = 0;
    for (i = h; i < MAXN && Ldata[HashTable[i]]->this_id != key; i = (i + 1) % MAXN)
    {
        count++;
        if (count == MAXN)
        {
            return -1;
        }
    }
    return HashTable[i];
}

int main()
{
    int N;
    int start1_id, start2_id, i;
    scanf("%d %d %d", &start1_id, &start2_id, &N);
    char temp;
    int this_id, next_id;

    for (i = 0; i < N; i++)
    {
        scanf("%d %c %d", &this_id, &temp, &next_id);
        Ldata[i] = (Lnode)malloc(sizeof(struct LNODE));
        Ldata[i]->this_id = this_id;
        Ldata[i]->next_id = next_id;
        Ldata[i]->belongL1 = 0;
        Insert(this_id, i);
    }

    this_id = start1_id;
    while (1)
    {
        i = Find(this_id);
        Ldata[i]->belongL1 = 1;
        if (Ldata[i]->next_id == -1)
        {
            break;
        }
        this_id = Ldata[i]->next_id;
    }

    int suffixstart = -1, flag = 0;
    this_id = start2_id;
    while (1)
    {
        i = Find(this_id);
        if (i == -1)
        {
            flag = 0;
            break;
        }
        if (Ldata[i]->belongL1)
        {
            suffixstart = Ldata[i]->this_id;
            flag = 1;
            break;
        }
        if (Ldata[i]->next_id == -1)
        {
            break;
        }
        this_id = Ldata[i]->next_id;
    }
    if (flag)
    {
        printf("%05d\n", suffixstart);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}

