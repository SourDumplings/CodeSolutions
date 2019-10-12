#include <stdio.h>

// 对于完全二叉搜索树的层序遍历序列中（从1开始），根节点的下标为i，则其左右子节点的下标分别为2*i和2*i+1

#define MAX 1001

int k = 0;

void Sort(int data[], int left, int right)
{
    int i = left;
    int j = right;
    int key = data[(left+right)/2];
    int temp;

    while (i <= j)
    {
        for (; data[i] < key; i++);
        for (; data[j] > key; j--);

        if (i <= j)
        {
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++;
            j--;
        }
    }

    if (i < right)
    {
        Sort(data, i, right);
    }
    if (j > left)
    {
        Sort(data, left, j);
    }

    return;
}

void LevelOrderTraversal(int data[], int N, int root, int result[])
{
    // 即将完全二叉搜索树再中序遍历一遍，赋值到层序遍历序列的相应位置
    while (root <= N)
    {
        LevelOrderTraversal(data, N, 2*root, result);
        result[root-1] = data[k++];
        LevelOrderTraversal(data, N, 2*root+1, result);
        return;
    }
}

int main()
{
    int N;
    int i;
    int data[MAX];
    int result[MAX];

    scanf("%d", &N);

    for (i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
    }

    // 对录入的序列进行排序，相当于得到了完全二叉搜索树的中序遍历
    Sort(data, 0, N-1);

    // 得到层序遍历序列
    LevelOrderTraversal(data, N, 1, result);

    // 输出层序遍历序列
    for (i = 0; i < N - 1; i++)
    {
        printf("%d ", result[i]);
    }
    printf("%d\n", result[i]);


    return 0;
}
