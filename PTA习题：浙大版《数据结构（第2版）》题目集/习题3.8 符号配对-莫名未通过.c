/*
 @Date    : 2017-11-14 09:33:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5869
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX 200
#define ERROR -1

typedef struct NODE *List;
struct NODE
{
    int c; // 四种符号分别编号为正负的1,2,3,4，左负右正。
    List next;
};

void Attach(List L, int c)
{
    // printf("%d has been added", c);
    List r, temp;
    for (r = L; r->next; r = r->next);
    temp = (List)malloc(sizeof(struct NODE));
    temp->c = c;
    temp->next = NULL;
    r->next = temp;
    r = temp;
    return;
}

int Check(List L, int c)
{
    List r, temp;
    r = L;
    int pass = 0;
    while (r->next)
    {
        if (r->next->c == -1 * c)
        {
            // printf("%d is OK", c);
            pass = 1;
            temp = r->next;
            r->next = temp->next;
            free(temp);
            break;
        }
        r = r->next;
    }
    if (!pass)
    {
        return c;
    }
    else
    {
        return 0;
    }
}

int main()
{
    List L;
    L = (List)malloc(sizeof(struct NODE));
    L->next = NULL;
    char s[MAX];
    int i = 0;
    int flag = 0;
    while (1)
    {
        // 输入句子，顺便检查左符号是否缺少
        scanf("%c", &s[i]);
        if (i > 0)
        {
            if (s[i-1] == '.' && s[i] == '\n')
            {
                break;
            }
        }
        if (!flag)
        {
            if (i > 0)
            {
                if (s[i-1] == '/' && s[i] == '*')
                {
                    Attach(L, -1);
                }
                else if (i > 1 && s[i-2] != '/' && s[i-1] == '*' && s[i] == '/')
                {
                    flag = Check(L, 1);
                }
            }
            switch (s[i])
            {
                case '(' : Attach(L, -2); break;
                case '[' : Attach(L, -3); break;
                case '{' : Attach(L, -4); break;
                case ')' : flag = Check(L, 2); break;
                case ']' : flag = Check(L, 3); break;
                case '}' : flag = Check(L, 4); break;
            }
        }
        i++;
    }

    if (!flag)
    {
        // 检查是否有缺少右符号的
        if (L->next)
        {
            // 缺少右符号
            flag = L->next->c;
        }
    }
    else if (flag > 0)
    {
        // 缺少左符号
        printf("NO\n");
        printf("?-");
        switch (flag)
        {
            case 1 : printf("*/"); break;
            case 2 : printf(")"); break;
            case 3 : printf("]"); break;
            case 4 : printf("}"); break;
        }
        putchar('\n');
        return 0;
    }

    if (flag < 0)
    {
        printf("NO\n");
        switch (flag)
        {
            case -1 : printf("/*"); break;
            case -2 : printf("("); break;
            case -3 : printf("["); break;
            case -4 : printf("{"); break;
        }
        printf("-?\n");
    }
    else
    {
        printf("YES\n");
    }
    return 0;
}

