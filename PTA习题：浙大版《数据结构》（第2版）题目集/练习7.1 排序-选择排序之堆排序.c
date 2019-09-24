#include <stdio.h>

void Swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    return;
}

void PercDown(int num[], int p, int N)
{
    int x = num[p];
    int parent, child;
    for (parent = p; parent * 2 < N - 1; parent = child)
    {
        child = parent * 2 + 1;
        if (child != N - 1 && num[child] < num[child+1])
        {
            child++;
        }
        if (x >= num[child])
        {
            break;
        }
        else
        {
            num[parent] = num[child];
        }
    }
    num[parent] = x;
    return;
}

void Heap_Sort(int num[], int N)
{
    int i;
    // 建立最大堆
    for (i = N / 2 - 1; i >= 0; i--)
    {
        PercDown(num, i, N);
    }
    // 将最大堆的堆顶元素删除，并放到最后面去
    for (i = N - 1; i > 0; i--)
    {
        Swap(&num[0], &num[i]);
        // 将新的堆顶下滤，即将除了刚刚放到最后面的元素之外的元素调整成最大堆
        PercDown(num, 0, i);
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
    Heap_Sort(num, N);
    for (i = 0; i < N - 1; i++)
    {
        printf("%d ", num[i]);
    }
    printf("%d\n", num[i]);
    return 0;
}
