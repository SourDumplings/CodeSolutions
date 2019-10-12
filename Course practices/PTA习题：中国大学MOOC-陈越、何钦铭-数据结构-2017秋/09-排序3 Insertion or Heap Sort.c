#include <stdio.h>

char JudgeMethod(int now[], int N)
{
    int i;
    // 排除前几个元素相等的情况
    for (i = 0; i < N - 1 && now[i] == now[i+1]; i++);
    return now[i] < now[i+1] ? 'I' : 'H';
}

void NextInsertion(int now[], int N)
{
    printf("Insertion Sort\n");
    int i;
    // 找到第一个破坏从小到大序列的元素的下标为i+1
    for (i = 0; now[i] <= now[i+1]; i++);
    int temp = now[++i];
    for (; i > 0 && temp <= now[i-1]; i--)
    {
        now[i] = now[i-1];
    }
    now[i] = temp;
    return;
}

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void PercDown(int now[], int p, int n)
{
    int x = now[p];
    int parent, child;
    for (parent = p; parent * 2 < n - 1; parent = child)
    {
        child = parent * 2 + 1;
        if (child < n - 1 && now[child] < now[child+1])
        {
            child++;
        }
        if (x >= now[child])
        {
            break;
        }
        else
        {
            now[parent] = now[child];
        }
    }
    now[parent] = x;
    return;
}

void NextHeap(int now[], int N)
{
    printf("Heap Sort\n");
    int i;
    // 找到堆的最后一个叶子节点的下标为i, 堆中共有i+1个元素
    for (i = N - 1; now[i] >= now[0]; i--);
    Swap(&now[i], &now[0]);
    PercDown(now, 0, i);
    return;
}

int main()
{
    int N;
    scanf("%d", &N);
    int A[N];
    int i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    int now[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &now[i]);
    }
    char judge = JudgeMethod(now, N);
    switch (judge)
    {
        case 'I' : NextInsertion(now, N); break;
        case 'H' : NextHeap(now, N);
    }
    for (i = 0; i < N; i++)
    {
        if (i)
        {
            putchar(' ');
        }
        printf("%d", now[i]);
    }
    putchar('\n');
    return 0;
}
