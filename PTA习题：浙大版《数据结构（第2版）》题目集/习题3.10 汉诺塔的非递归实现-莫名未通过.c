/*
 @Date    : 2017-11-16 17:59:28
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5892
汉诺塔的非递归算法描述如下：
首先容易证明，当盘子的个数为n时，移动的次数应等于2^n - 1。
一位美国学者发现一种出人意料的方法，只要轮流进行两步操作就可以了。
首先把三根柱子按顺序排成品字型，把所有的圆盘按从大到小的顺序放在柱子A上。
根据圆盘的数量确定柱子的排放顺序：若n为偶数，按顺时针方向依次摆放 A B C；
若n为奇数，按顺时针方向依次摆放 A C B。
（1）按顺时针方向把圆盘1从现在的柱子移动到下一根柱子，即当n为偶数时，若圆盘1在柱子A，则把它移动到B；
若圆盘1在柱子B，则把它移动到C；若圆盘1在柱子C，则把它移动到A。
（2）接着，把另外两根柱子上可以移动的圆盘移动到新的柱子上。
即把非空柱子上的圆盘移动到空柱子上，当两根柱子都非空时，移动较小的圆盘
这一步没有明确规定移动哪个圆盘，你可能以为会有多种可能性，其实不然，可实施的行动是唯一的。
（3）反复进行（1）（2）操作，最后就能按规定完成汉诺塔的移动。
即就是：
第一步：将最小圆盘移动到下一个柱子上，也就是b
第二步：对a柱子和c柱子进行顶上最小的元素进行判断，把小一点的那个圆盘移动到大一点的那个圆盘（有空则摞在空柱子上）。
重复上述两步就可以得到答案。
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXN 100
#define ERROR 0

typedef struct STACK *Stack;
struct STACK
{
    int data[MAXN];
    char name;
    int top;
    int capacity;
};

void Push(Stack S, int X)
{
    if (S->top < S->capacity)
    {
        S->data[++S->top] = X;
    }
    return;
}

int Pop(Stack S)
{
    if (S->top > -1)
    {
        return S->data[S->top--];
    }
    else
    {
        return ERROR;
    }
}

int FindMin3(Stack S[])
{
    int min = S[0]->data[S[0]->top];
    int i;
    int min_index = 0;
    for (i = 1; i < 3; i++)
    {
        if (S[i]->top > -1 && S[i]->data[S[i]->top] < min)
        {
            min_index = i;
            min = S[i]->data[S[i]->top];
        }
    }
    return min_index;
}

void MoveStep2(Stack S[], int r1, int r2)
{
    int min_i, des_i;
    if (S[r1]->top == -1)
    {
        min_i = r2;
    }
    else if (S[r2]->top == -1)
    {
        min_i = r1;
    }
    else
    {
        min_i = S[r1]->data[S[r1]->top] < S[r2]->data[S[r2]->top] ?
        r1 : r2;
    }

    r1 = (min_i + 1) % 3;
    r2 = (min_i + 2) % 3;

    if (S[r1]->top == -1)
    {
        des_i = r1;
    }
    else if (S[r2]->top == -1)
    {
        des_i = r2;
    }
    else
    {
        des_i = S[r1]->data[S[r1]->top] > S[min_i]->data[S[min_i]->top] ?
        r1 : r2;
    }

    Push(S[des_i], Pop(S[min_i]));
    printf("%c -> %c\n", S[min_i]->name, S[des_i]->name);

    return;
}

int main()
{
    Stack S[3];
    int N, i;
    scanf("%d", &N);

    for (i = 0; i < 3; i++)
    {
        S[i] = (Stack)malloc(sizeof(struct STACK));
        S[i]->capacity = N;
        S[i]->top = -1;
    }

    S[0]->name = 'a';
    if (N % 2)
    {
        S[1]->name = 'c';
        S[2]->name = 'b';
    }
    else
    {
        S[1]->name = 'b';
        S[2]->name = 'c';
    }

    for (i = N; i > 0; i--)
    {
        Push(S[0], i);
    }

    int min_i;
    int maxstep = (int)pow(2, N) - 1;
    int count = 0;
    while (count < maxstep)
    {
        // 第一步
        min_i = FindMin3(S);
        // printf("S[0]->data[S[0]->top] = %d, S[1]->data[S[1]->top] = %d, S[2]->data[S[2]->top] = %d\n",
        //     S[0]->data[S[0]->top], S[1]->data[S[1]->top], S[2]->data[S[2]->top]);
        // printf("min_i = %d\n", min_i);
        Push(S[(min_i+1)%3], Pop(S[min_i]));
        printf("%c -> %c\n", S[min_i]->name, S[(min_i+1)%3]->name);
        if (++count == maxstep)
        {
            break;
        }
        // 第二步
        MoveStep2(S, min_i, (min_i+2)%3);
        count++;
    }

    for (i = 0; i < 3; i++)
    {
        free(S[i]);
    }

    return 0;
}

