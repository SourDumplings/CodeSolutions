#include <stdio.h>
#include <stdlib.h>

int maxp; // 记录有序序列的最大周期，即第一个破坏升序的元素的下标

char JudgeMethod(int A[], int now[], int N)
{
    int i;
    int temp = now[0];
    for (i = 1; i < N; i++)
    {
        if (now[i] < temp)
        {
            maxp = i;
            break;
        }
        temp = now[i];
    }
    // 从后往前比较两个序列是否一致
    for (i = N - 1; i >= maxp; i--)
    {
        if (now[i] != A[i])
        {
            return 'M';
        }
    }
    return 'I';
}

void NextInsertion(int now[])
{
    printf("Insertion Sort\n");
    int i;
    int temp = now[maxp];
    for (i = maxp; i > 0 && now[i-1] > temp; i--)
    {
        now[i] = now[i-1];
    }
    now[i] = temp;
    return;
}

void Merge(int now[], int Temnow[], int L, int R, int RightEnd)
{
    int LeftEnd = R - 1;
    int temp = L;
    int NumElements = RightEnd - L + 1;
    int i;
    while (L <= LeftEnd && R <= RightEnd)
    {
        Temnow[temp++] = now[L] <= now[R] ? now[L++]:now[R++];
    }
    while (L <= LeftEnd)
    {
        Temnow[temp++] = now[L++];
    }
    while (R <= RightEnd)
    {
        Temnow[temp++] = now[R++];
    }
    for (i = 0; i < NumElements; i++, RightEnd--)
    {
        now[RightEnd] = Temnow[RightEnd];
    }
    return;
}

void NextMerge(int now[], int N)
{
    printf("Merge Sort\n");
    int p, tryp, i;
    int start = 0; // 子列的开端
    int end;
    int flag = 1;

    // 得到有序子列的长度
    if (maxp < 4)
    {
        p = 2;
    }
    else
    {
        for (tryp = 4; tryp <= maxp; tryp *= 2)
        {
            while (start + tryp <= N)
            {
                // 扫描各个以tryp为长度的子列，看是否有序
                start += tryp;
                end = start + tryp < N ? start + tryp - 1 : N - 1;
                for (i = start; i < end; i++)
                {
                    if (now[i] > now[i+1])
                    {
                        flag = 0; // 这个tryp超过了有序子列长度了
                        break;
                    }
                }
                if (!flag)
                {
                    break;
                }
            }
            start = 0;
            if (flag)
            {
                p = tryp;
            }
            else
            {
                p = tryp / 2;
                break;
            }
        }
    }

    // 得到下一次合并后的序列
    int *Temnow;
    Temnow = (int *)malloc(N * sizeof(int));
    if (Temnow)
    {
        for (i = 0; i + 2 * p <= N; i += 2 * p)
        {
            Merge(now, Temnow, i, i+p, i+2*p-1);
        }
        // 归并最后两个子列
        if (i + p < N)
        {
            // 最后剩两个子列
            Merge(now, Temnow, i, i+p, N-1);
        }
        // 若最后只剩一个子列，则不需要进行任何操作
    }
    free(Temnow);

    return;
}

int main()
{
    int N;
    scanf("%d", &N);
    int A[N], i;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &A[i]);
    }
    int now[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &now[i]);
    }
    char judge = JudgeMethod(A, now, N);
    switch (judge)
    {
        case 'I': NextInsertion(now); break;
        case 'M': NextMerge(now, N); break;
    }
    for (i = 0; i < N; i++)
    {
        printf("%d", now[i]);
        if (i < N - 1)
        {
            putchar(' ');
        }
    }
    putchar('\n');
    return 0;
}
