/*
 @Date    : 2017-12-08 20:52:44
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

int compare(const void *a, const void *b)
{
    return (*(Node *)a)->key - (*(Node *)b)->key;
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

    int flag = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (temp[j]->add == start)
            {
                L[l] = temp[j];
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            printf("0 %d", start);
            return 0;
        }
        start = L[l]->next;
        l++;
        if (start == -1)
        {
            break;
        }
    }

    qsort(L, l, sizeof(L[0]), compare);

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

