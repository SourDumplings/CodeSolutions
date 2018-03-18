/*
 @Date    : 2017-12-09 09:31:24
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1052
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct NODE *Node;
struct NODE
{
    int add;
    int key;
    int next;
};

int comparekey(const void *a, const void *b)
{
    return (*(Node *)a)->key - (*(Node *)b)->key;
}

int compareadd(const void *a, const void *b)
{
    return (*(Node *)a)->add - (*(Node *)b)->add;
}

// int FindAdd(Node temp[], int s, int e, int add)
// {
//     if ((s == e && temp[s]->add != add) || (e < s))
//     {
//         return -1;
//     }
//     int c = (s + e) / 2;
//     if (temp[c]->add == add)
//     {
//         return c;
//     }
//     else if (temp[c]->add < add)
//     {
//         return FindAdd(temp, c+1, e, add);
//     }
//     else
//     {
//         return FindAdd(temp, s, c-1, add);
//     }
// }
//

int FindAdd(Node temp[], int s, int e, int add)
{
    int c;
    while (s <= e)
    {
        c = (s + e) / 2;
        if (temp[c]->add == add)
        {
            return c;
        }
        else if (temp[c]->add < add)
        {
            s = c + 1;
        }
        else
        {
            e = c - 1;
        }
    }
    return -1;
}

int main()
{
    int N, start;
    scanf("%d %d", &N, &start);
    int i, j;
    Node temp[N], L[N];
    int l = 0;
    for (i = 0; i < N; i++)
    {
        temp[i] = (Node)malloc(sizeof(struct NODE));
        scanf("%d %d %d", &temp[i]->add, &temp[i]->key, &temp[i]->next);
    }

    qsort(temp, N, sizeof(L[0]), compareadd);

    for (i = 0; i < N; i++)
    {
        j = FindAdd(temp, 0, N-1, start);
        if (j == -1)
        {
            break;
        }
        L[l] = temp[j];
        start = temp[j]->next;
        l++;
    }

    if (l == 0)
    {
        printf("%d %d", l, start);
        return 0;
    }

    qsort(L, l, sizeof(L[0]), comparekey);

    start = L[0]->add;
    for (i = 0; i < l - 1; i++)
    {
        L[i]->next = L[i+1]->add;
    }
    L[l-1]->next = -1;

    printf("%d %05d\n", l, L[0]->add);
    for (i = 0; i < l; i++)
    {
        if (L[i]->next != -1)
        {
            printf("%05d %d %05d\n", L[i]->add, L[i]->key, L[i]->next);
        }
        else
        {
            printf("%05d %d -1\n", L[i]->add, L[i]->key);
        }
    }
    return 0;
}



