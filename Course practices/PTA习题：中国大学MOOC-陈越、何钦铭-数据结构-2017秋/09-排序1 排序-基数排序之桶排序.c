#include <stdio.h>
#include <stdlib.h>

# define MAX 100000

int D = 19; // 需要的桶的个数

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

typedef struct BUCKET *Bucket;
struct BUCKET
{
    int data;
    Bucket next;
};

void FillBucket(int num[], int N, int n)
{
    Bucket head[D]; // 每个桶的头结点
    Bucket rear[D]; // 每个桶的最后一个结点
    // 初始化head[]
    int i;
    for (i = 0; i < D; i++)
    {
        head[i] = (Bucket)malloc(sizeof(struct BUCKET));
        rear[i] = head[i];
        head[i]->next = NULL;
    }
    // 将元素按照n位进行入桶
    int d;
    Bucket temp;
    for (i = 0; i < N; i++)
    {
        d = (num[i] / n) % 10;
        temp = (Bucket)malloc(sizeof(struct BUCKET));
        temp->data = num[i];
        temp->next = NULL;
        rear[d+9]->next = temp;
        rear[d+9] = temp;
    }
    // 依次读取桶中的元素形成新的序列
    i = 0;
    for (d = 0; d < D; d++)
    {
        temp = head[d];
        while (temp->next)
        {
            temp = temp->next;
            num[i++] = temp->data;
        }
    }
    // 释放链表节点的空间
    Bucket pre;
    for (d = 0; d < D; d++)
    {
        pre = head[d];
        while (pre->next)
        {
            temp = pre->next;
            free(pre);
            pre = temp;
        }
    }
    return;
}

void Bucket_Sort(int num[], int N)
{
    int i = 1;
    for (i = 1; i <= MAX; i *= 10)
    {
        // 次位优先原则进行桶排序
        FillBucket(num, N, i);
    }
    return;
}

int main()
{
    int N;
    scanf("%d", &N);
    int num[N];
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &num[i]);
    }
    Bucket_Sort(num, N);
    for (i = 0; i < N - 1; i++)
    {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[i]);
    return 0;
}
