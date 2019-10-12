#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 64

typedef struct DATA *Data;
struct DATA
{
    int f;
    char c;
};

Data D[MAX];  // 存放权重信息的

typedef struct HTNode *Huf;
struct HTNode
{
    int Weight;
    Huf Left;
    Huf Right;
};

typedef struct HNode *MinHeap;
struct HNode
{
    Huf *data;
    int size;
    int capacity;
};

MinHeap CreateHeap(int maxsize)
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
    H->data = (Huf *)malloc((maxsize+1)*sizeof(struct HTNode));
    H->size = 0;
    H->capacity = maxsize;
    H->data[0] = (Huf)malloc(sizeof(struct HTNode));
    H->data[0]->Weight = 0;
    H->data[0]->Left = H->data[0]->Right = NULL;
    return H;
}

void PercDown(MinHeap H, int p)
{
    int parent, child;
    Huf x;
    x = H->data[p];
    for (parent = p; parent * 2 <= H->size; parent = child)
    {
        child = parent * 2;
        if (child != H->size && H->data[child]->Weight > H->data[child+1]->Weight)
        {
            child++;
        }
        if (x->Weight <= H->data[child]->Weight)
        {
            break;
        }
        else
        {
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = x;
    return;
}

void BuildHeap(MinHeap H)
{
    int i;
    for (i = H->size/2; i > 0; i--)
    {
        PercDown(H, i);
    }
    return;
}

MinHeap ReadData(MinHeap H, int N)
{
    int i;
    for (i = 1; i <= N; i++)
    {
        D[i] = (Data)malloc(sizeof(struct DATA));
        getchar();
        scanf("%c %d", &D[i]->c, &D[i]->f);
        H->data[i] = (Huf)malloc(sizeof(struct HTNode));
        H->data[i]->Weight = D[i]->f;
        H->data[i]->Left = H->data[i]->Right = NULL;
        H->size++;
    }
    return H;
}

Huf DeleteMin(MinHeap H)
{
    int parent, child;
    Huf minitem, x;
    if (H->size == 0)
    {
        printf("最小堆空了");
        return NULL;
    }
    minitem = H->data[1];
    x = H->data[H->size--];
    for (parent = 1; parent * 2 <= H->size; parent = child)
    {
        child = parent * 2;
        if (child != H->size && H->data[child]->Weight > H->data[child+1]->Weight)
        {
            child++;
        }
        if (x->Weight <= H->data[child]->Weight)
        {
            break;
        }
        else
        {
            H->data[parent] = H->data[child];
        }
    }
    H->data[parent] = x;
    return minitem;
}

void Insert(MinHeap H, Huf x)
{
    int i;
    if (H->size == H->capacity)
    {
        printf("最小堆满了\n");
        return;
    }
    i = ++H->size;
    for (; H->data[i/2]->Weight > x->Weight; i /= 2)
    {
        H->data[i] = H->data[i/2];
    }
    H->data[i] = x;
    return;
}

Huf Huffman(MinHeap H)
{
    int i, N;
    Huf T;
    BuildHeap(H);
    N = H->size;
    for (i = 1; i < N; i++)
    {
        T = (Huf)malloc(sizeof(struct HTNode));
        T->Left = DeleteMin(H);
        T->Right = DeleteMin(H);
        T->Weight = T->Left->Weight + T->Right->Weight;
        Insert(H, T);
    }
    return DeleteMin(H);
}

int WPL(Huf T, int Depth)
{
    if (!T)
    {
        return 0;
    }
    if (!T->Left && !T->Right)
    {
        // T为叶节点
        return (Depth * T->Weight);
    }
    else
    {
        // T一定有两个孩子
        return (WPL(T->Left, Depth+1) + WPL(T->Right, Depth+1));
    }
}

int FindWeight(char c)
{
    int i;
    for (i = 1; i < MAX; i++)
    {
        if (D[i]->c == c)
        {
            return D[i]->f;
        }
    }
    return 0;
}

Huf AddTreeNode(Huf T, char c, char eachcode[], int codelen, int *answer)
{
    int i;
    int weight = FindWeight(c);
    Huf Troot = T;
    for (i = 0; i < codelen - 1; i++)
    {
        if (eachcode[i] == '0')
        {
            if (!T->Left)
            {
                T->Left = (Huf)malloc(sizeof(struct HTNode));
                T = T->Left;
                T->Left = T->Right = NULL;
            }
            else if (!T->Left->Left && !T->Left->Right)
            {
                *answer = 0;
                return Troot;
            }
            else
            {
                T = T->Left;
            }
        }
        else if (eachcode[i] == '1')
        {
            if (!T->Right)
            {
                T->Right = (Huf)malloc(sizeof(struct HTNode));
                T = T->Right;
                T->Left = T->Right = NULL;
            }
            else if (!T->Right->Left && !T->Right->Right)
            {
                *answer = 0;
                return Troot;
            }
            else
            {
                T = T->Right;
            }
        }
    }

    // 插入最后一位编码
    if (eachcode[i] == '0')
    {
        if (!T->Left)
        {
            T->Left = (Huf)malloc(sizeof(struct HTNode));
            T = T->Left;
            T->Left = T->Right = NULL;
            T->Weight = weight;
        }
        else
        {
            *answer = 0;
            return Troot;
        }
    }
    else if (eachcode[i] == '1')
    {
        if (!T->Right)
        {
            T->Right = (Huf)malloc(sizeof(struct HTNode));
            T = T->Right;
            T->Left = T->Right = NULL;
            T->Weight = weight;
        }
        else
        {
            *answer = 0;
            return Troot;
        }
    }
    return Troot;
}

int ReadStudentCode(int mincodel, int N, Data D[])
{
    int i, answer = 1;
    char code[N][MAX];
    int lcode[N];
    int sumcodelen;
    char c;
    Huf T;

    // 头空节点
    T = (Huf)malloc(sizeof(struct HTNode));
    T->Left = T->Right = NULL;
    T->Weight = 0;
    for (i = 0; i < N; i++)
    {
        getchar();
        scanf("%c %s", &c, code[i]);
        if (!answer)
        {
            continue;
        }
        lcode[i] = strlen(code[i]);
        if (lcode[i] > N - 1)
        {
            answer = 0;
            continue;
        }
        T = AddTreeNode(T, c, code[i], lcode[i], &answer);
    }
    sumcodelen = WPL(T, 0);
    if (sumcodelen > mincodel)
    {
        answer = 0;
    }
    return answer;
}

int main()
{
    int N;
    scanf("%d", &N);
    MinHeap H = CreateHeap(N); // 创建一个空的、容量为N的最小堆
    H = ReadData(H, N); // 将f[]读入到H->data中
    Huf T = Huffman(H); // 建立哈夫曼树
    int mincodel = WPL(T, 0);

    int M;
    int i;
    int answer;
    scanf("%d", &M);
    for (i = 0; i < M; i++)
    {
        answer = ReadStudentCode(mincodel, N, D);
        if (answer)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
