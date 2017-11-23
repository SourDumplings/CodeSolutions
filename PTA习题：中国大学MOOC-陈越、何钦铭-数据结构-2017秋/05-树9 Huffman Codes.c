#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CMAX 64

typedef struct DATA *Data;
struct DATA
{
    char data;
    int freq;
};

typedef struct HTNode *Huf;
struct HTNode
{
    int weight;
    Huf left;
    Huf right;
    int h; // 记录节点所在的树的高度，根节点为0, 即编码的长度
};

typedef struct HNode *MinH;
struct HNode
{
    Huf *data;
    int size;
    int capacity;
};


void InputData(Data D[], int N)
{
    int i;

    for (i = 0; i < N; i++)
    {
        D[i] = (Data)malloc(sizeof(struct DATA));
        scanf("%c %d", &D[i]->data, &D[i]->freq);
        if (getchar() == ' ')
        {
            continue;
        }
    }
    return;
}

MinH CreateHeap(Data D[], int maxsize)
{
    MinH H;
    int i;

    H = (MinH)malloc(sizeof(struct HNode));
    H->data = (Huf *)malloc((maxsize + 1) * sizeof(struct HTNode));
    H->size = 0;
    H->capacity = maxsize;
    H->data[0] = (Huf)malloc(sizeof(struct HTNode));
    H->data[0]->weight = 0; // 定义最小堆的哨兵节点

    for (i = 1; i <= maxsize; i++)
    {
        H->data[i] = (Huf)malloc(sizeof(struct HTNode));
        H->data[i]->weight = D[i-1]->freq;
        H->data[i]->left = H->data[i]->right = NULL;
        H->size++;
    }

    return H;
}

void PercDown(MinH H, int p)
{
    int parent, child;
    Huf X;

    X = H->data[p];
    for (parent = p; parent * 2 <= H->size; parent = child)
    {
        child = parent * 2;
        if ((child != H->size) && (H->data[child]->weight > H->data[child+1]->weight))
        {
            child++;
        }

        if (X->weight <= H->data[child]->weight)
        {
            break;
        }
        else
        {
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = X;

    return;
}

void BuildHeap(MinH H)
{
    int i;

    for (i = H->size / 2; i > 0; i--)
    {
        PercDown(H, i);
    }

    return;
}

Huf DeleteMin(MinH H)
{
    int parent, child;
    Huf minitem, X;
    if (H->size == 0)
    {
        printf("最小堆为空\n");
        return NULL;
    }

    minitem = H->data[1];
    X = H->data[H->size--];
    for (parent = 1; parent * 2 <= H->size; parent = child)
    {
        child = parent * 2;
        if ((child != H->size) && (H->data[child]->weight > H->data[child+1]->weight))
        {
            child++;
        }

        if (X->weight <= H->data[child]->weight)
        {
            break;
        }
        else
        {
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = X;

    return minitem;
}

void Insert(MinH H, Huf X)
{
    int i;

    if (H->size == H->capacity)
    {
        printf("最小堆满了\n");
        return;
    }

    i = ++H->size;
    for (; H->data[i/2]->weight > X->weight; i /= 2)
    {
        H->data[i] = H->data[i/2];
    }
    H->data[i] = X;
    return;
}

Huf Huffman(MinH H)
{
    int i, N;
    Huf T;

    BuildHeap(H);
    N = H->size;
    for (i = 1; i < N; i++)
    {
        T = (Huf)malloc(sizeof(struct HTNode));
        T->left = DeleteMin(H);
        T->right = DeleteMin(H);
        T->weight = T->left->weight + T->right->weight;
        T->h = -1;
        T->left->h = -1;
        T->right->h = -1;
        Insert(H, T);
    }
    return DeleteMin(H);
}

void PreOrderTraversal(Huf T, int *pwpl)
// 计算编码树的wpl
{
    T->h++;
    if (T->left || T->right)
    {
        T->left->h = T->h;
        PreOrderTraversal(T->left, pwpl);
        T->right->h = T->h;
        PreOrderTraversal(T->right, pwpl);

    }
    else
    {
        *pwpl += T->h * T->weight;
    }
    return;
}

int FindWeight(Data D[], int N, char data)
{
    int i;
    for (i = 0; i < N; i++)
    {
        if (D[i]->data == data)
        {
            return D[i]->freq;
        }
    }
}

void FreeTree(Huf T)
{
    if (!T)
    {
        return;
    }
    else
    {
        FreeTree(T->left);
        FreeTree(T->right);
        free(T);
        return;
    }
}

// 记录并判断学生的编码，需要修改！
int InputJudgeCode(Huf T_s, int N, Data D[], int wpl0)
{
    int i;
    char data;
    char code[N][CMAX];
    int j;
    int codelength;
    Huf T_now;
    int wpl = 0;
    int flag = 1;

    // 编码树的根空节点
    T_s = (Huf)malloc(sizeof(struct HTNode));
    T_s->left = T_s->right = NULL;

    for (i = 0; i < N; i++)
    {
        T_now = T_s;
        getchar();
        scanf("%c %s", &data, code[i]);

        if (!flag)
        {
            continue;
        }

        codelength = strlen(code[i]);
        for (j = 0; j < codelength - 1; j++)
        {
            if (code[i][j] == '0')
            {
                if (!T_now->left)
                {
                    T_now->left = (Huf)malloc(sizeof(struct HTNode));
                    T_now = T_now->left;
                    T_now->left = T_now->right = NULL;
                    continue;
                }
                else
                {
                    T_now = T_now->left;
                    if (T_now->left || T_now->right)
                    {
                        continue;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }
            if (code[i][j] == '1')
            {
                if (!T_now->right)
                {
                    T_now->right = (Huf)malloc(sizeof(struct HTNode));
                    T_now = T_now->right;
                    T_now->left = T_now->right = NULL;
                    continue;
                }
                else
                {
                    T_now = T_now->right;
                    if (T_now->left || T_now->right)
                    {
                        continue;
                    }
                    else
                    {
                        flag = 0;
                        break;
                    }
                }
            }
        }
        if (!flag)
        {
            continue;
        }

        // 读取最后一位编码
        if (code[i][j] == '0')
        {
            if (T_now->left)
            {
                flag = 0;
                continue;
            }
            else
            {
                T_now->left = (Huf)malloc(sizeof(struct HTNode));
                T_now = T_now->left;
                T_now->left = T_now->right = NULL;
                T_now->h = codelength;
                T_now->weight = FindWeight(D, N, data);
            }
        }
        else if (code[i][j] == '1')
        {
            if (T_now->right)
            {
                flag = 0;
                continue;
            }
            else
            {
                T_now->right = (Huf)malloc(sizeof(struct HTNode));
                T_now = T_now->right;
                T_now->left = T_now->right = NULL;
                T_now->h = codelength;
                T_now->weight = FindWeight(D, N, data);
            }
        }

        //计算wpl并判断
        wpl += T_now->weight * T_now->h;
        if (wpl > wpl0)
        {
            flag = 0;
            continue;
        }
    }

    FreeTree(T_s);

    return flag;
}

int main()
{
    int N;
    scanf("%d\n", &N);

    // 录入数据
    Data D[N];
    InputData(D, N);

    // 建立哈夫曼树，计算最小wpl
    int wpl0 = 0;
    // 建立最小堆
    MinH H;
    H = CreateHeap(D, N);
    // 构造哈夫曼树
    Huf T;
    T = Huffman(H);
    // 计算wpl0
    PreOrderTraversal(T, &wpl0);

    // 输入每个学生的编码并判断
    int K;
    scanf("%d", &K);
    int i;
    int flag = 1;
    Huf T_s = NULL;
    for (i = 0; i < K; i++)
    {
        flag = InputJudgeCode(T_s, N, D, wpl0);
        if (!flag)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }

    return 0;
}

