/*
 @Date    : 2017-11-15 09:28:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5891
 */

#include <stdio.h>
#include <stdlib.h>

#define ERROR 0

typedef struct STACK *Stack;
struct STACK
{
    int capacity;
    int top;
};

int Push(Stack S)
{
    if (S->top < S->capacity - 1)
    {
        S->top++;
        return 1;
    }
    else
    {
        return ERROR;
    }
}

int Pop(Stack S)
{
    if (S->top > -1)
    {
        S->top--;
        return 1;
    }
    else
    {
        return ERROR;
    }
}

int main()
{
    int N, M;
    scanf("%d %d\n", &N, &M);
    Stack S;
    S = (Stack)malloc(sizeof(struct STACK));
    S->capacity = M;
    S->top = -1;
    int i;
    char C[101];
    int j, flag = 1;
    for (i = 0; i < N; i++)
    {
        flag = 1;
        gets(C);
        for (j = 0; C[j] != '\0'; j++)
        {
            switch (C[j])
            {
                case 'S' : flag = Push(S); break;
                case 'X' : flag = Pop(S); break;
            }
            if (!flag)
            {
                break;
            }
        }
        if (!flag || S->top != -1)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
        S->top = -1;
    }
    free(S);

    return 0;
}

