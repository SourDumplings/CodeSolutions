/*
 @Date    : 2017-11-16 20:11:39
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5893
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define ERROR -1
#define MAX 21

typedef struct STACK *Stack;
struct STACK
{
    char c[MAX];
    int top;
    int capacity;
};

int IsFull(Stack S)
{
    return S->top == S->capacity - 1;
}

int IsEmpty(Stack S)
{
    return S->top == -1;
}

void Push(Stack S, char C)
{
    if (!IsFull(S))
    {
        S->c[++S->top] = C;
    }
    return;
}

char Pop(Stack S)
{
    if (!IsEmpty(S))
    {
        return S->c[S->top--];
    }
    else
    {
        return ERROR;
    }
}

int main()
{
    Stack S;
    S = (Stack)malloc(sizeof(struct STACK));
    S->top = -1;
    char s[MAX];
    gets(s);
    int l = strlen(s);
    S->capacity = l;
    int i;
    int output = 0; // 记录已经输出的元素个数
    for (i = 0; i < l; i++)
    {
        if (isdigit(s[i]) ||
            ((s[i] == '-' || s[i] == '+') && (!i || s[i-1] == '(')))
        {
            // 如果s[i]是加减号并且s[i-1]是左括号或是s[i]是第一位，或者s[i]是数字，则考虑直接输出
            // 此为考虑输出数字以及数字前的符号
            if (output++)
            {
                // 如果不是第一个输出的元素，则输出一个空格
                putchar(' ');
            }
            if (s[i] != '+')
            {
                // 如果s[i]是加号则不输出该元素，排除正数前一个加号的情况
                putchar(s[i]);
            }
            while (s[i+1] == '.' || isdigit(s[i+1]))
            {
                // 如果下一位是小数点或者是数字则输出，直到下一位为符号为止
                // 这是处理小数点的情况
                i++;
                putchar(s[i]);
            }
        }
        else
        {
            // 对于其他情况
            if (s[i] == ')')
            {
                // 如果s[i]是右括号
                while (!IsEmpty(S) && S->c[S->top] != '(')
                {
                    // 对于栈非空并且栈顶元素不是左括号，即输出该括号范围内的所有元素
                    if (output++)
                    {
                        putchar(' ');
                    }
                    putchar(Pop(S));
                }
                if (!IsEmpty(S))
                {
                    // 循环结束如果栈非空，则弹出栈顶的左括号
                    Pop(S);
                }
            }
            else
            {
                // 如果s[i]不是右括号
                if (IsEmpty(S))
                {
                    // 栈空则将s[i]压栈
                    Push(S, s[i]);
                    continue;
                }
                while (!IsEmpty(S) && S->c[S->top] != '(')
                {
                    // 如果栈非空并且栈顶元素不是左括号
                    // 输出栈中元素直到s[i]的优先级比栈顶元素大
                    if (s[i] == '(' ||
                        ((s[i] == '*' || s[i] == '/') && (S->c[S->top] == '-' || S->c[S->top] == '+')))
                    {
                        // s[i]的运算优先级大于栈顶元素
                        break;
                    }
                    if (output++)
                    {
                        putchar(' ');
                    }
                    putchar(Pop(S));
                }
                // 将s[i]入栈
                Push(S, s[i]);
            }
        }
    }

    while (!IsEmpty(S))
    {
        // 输出栈中剩余符号
        if (output++)
        {
            putchar(' ');
        }
        if (S->c[S->top] != '(')
        {
            putchar(Pop(S));
        }
        else
        {
            Pop(S);
        }
    }
    putchar('\n');

    free(S);

    return 0;
}

