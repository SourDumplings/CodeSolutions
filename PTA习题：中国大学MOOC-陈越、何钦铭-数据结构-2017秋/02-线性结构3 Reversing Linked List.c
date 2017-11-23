#include <stdio.h>
#include <stdlib.h>

#define Null -1
#define MAXN  100001
// #define MAXN  7

typedef struct NODE *node;
struct NODE
{
    int data;
    int address;
    int next;
};

node L[MAXN+1] = {NULL};


// 找到L中对应地址的节点，返回指向该节点的指针
node Sort(int addr, int N)
{
    int i;

    for (i = 1; i <= N; i++)
    {
        if (L[i]->address == addr)
        {
            return L[i];
        }
    }

    return NULL;
}

node Reverse(node head, int K, int N)
{
    int count = 1;
    int new, old, tmp, new_head;
    new = head->next;
    if (new == Null)
    {
        return NULL;
    }
    new_head = new;
    old = Sort(new, N)->next;
    if (old == Null)
    {
        return NULL;
    }
    while(count < K)
    {
        tmp = Sort(old, N)->next;
        Sort(old, N)->next = new;
        new = old;
        old = tmp;
        count++;
    }
    Sort(head->next, N)->next = old;
    head->next = new;
    return Sort(new_head, N);
}

void Output(node head, int N)
{
    node p;
    while (Sort(head->next, N)->next != Null)
    {
        p = Sort(head->next, N);
        printf("%05d %d %05d\n", p->address, p->data, p->next);
        head = p;
    }
    p = Sort(head->next, N);
    printf("%05d %d %d\n", p->address, p->data, p->next);
}

int main()
{
    int addr_head;
    int N, K;
    int i;
    int n; // 记录最多调整的次数
    node head;

    scanf("%d %d %d", &addr_head, &N, &K);

    // L[0]为头空节点的指针
    L[0] = (node)malloc(sizeof(struct NODE));
    L[0]->next = addr_head;
    head = L[0];

    for (i = 1; i <= N; i++)
    {
        L[i] = (node)malloc(sizeof(struct NODE));
        scanf("%d %d %d", &(L[i]->address), &(L[i]->data), &(L[i]->next));
    }

    n = N / K;
    for (i = 0; i < n; i++)
    {
        head = Reverse(head, K, N);
        if (!head)
        {
            break;
        }
    }


    Output(L[0], N);

    return 0;
}
