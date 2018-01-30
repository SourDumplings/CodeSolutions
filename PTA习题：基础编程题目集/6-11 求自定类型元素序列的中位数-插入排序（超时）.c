#include <stdio.h>

#define MAXN 10
typedef float ElementType;

ElementType Median( ElementType A[], int N );

int main ()
{
    ElementType A[MAXN];
    int N, i;

    scanf("%d", &N);
    for ( i=0; i<N; i++ )
        scanf("%f", &A[i]);
    printf("%.2f\n", Median(A, N));

    return 0;
}

#include <stdlib.h>
typedef struct LINE *line;

struct LINE
{
    ElementType data;
    line next;
};

line sort(ElementType A[], int N, line h)
{
    int i;
    line temp = NULL, p = NULL;
    int flag = 0;

    p = h;

    // 插入后面的数
    for (i = 0; i <= N - 1; i++)
    {
        temp = (line)malloc(sizeof(struct LINE));
        temp->data = A[i];

        while (p->next)
        {
            if (temp->data < p->next->data)
            {
                temp->next = p->next;
                p->next = temp;
                flag = 1; // 标记已经将A[i]插入
                break;
            }
            else
            {
                p = p->next;
            }
        }

        if (!flag)
        {
            p->next = temp;
            temp->next = NULL;
        }

        p = h;
    }

    return h;
}

ElementType Median( ElementType A[], int N )
{
    line h = NULL, m;
    int i;

    // 创建空头节点
    h = (line)malloc(sizeof(struct LINE));
    h->next = NULL;

    // 插入排序
    h = sort(A, N, h);
    m = h->next;

    // for (i = 0; i < N - 1; i++)
    // {
    //     printf("%.2f\n", m->data);
    //     m = m->next;
    // }

    for (i = 0; i < N/2; i++)
    {
        m = m->next;
    }

    return m->data;
}
