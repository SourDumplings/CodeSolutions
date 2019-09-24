/*
 @Date    : 2017-11-13 14:30:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/434/problems/5860
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE *List;
struct NODE
{
    int data;
    List next;
};

List Read(int n)
{
    List L, temp, rear;
    L = (List)malloc(sizeof(struct NODE));
    L->next = NULL;
    rear = L;
    int i;
    for (i = 0; i < n; i++)
    {
        temp = (List)malloc(sizeof(struct NODE));
        scanf("%d", &temp->data);
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
    }
    return L;
}

void MaxUpL(List L)
{
    int thislength = 1, maxlength = 1;
    List front = L->next, rear, maxlrear, maxlfront;
    int last;
    maxlrear = front;
    maxlfront = front;
    while (front->next)
    {
        rear = front;
        while (rear->next)
        {
            last = rear->data;
            rear = rear->next;
            if (rear->data > last)
            {
                thislength++;
                if (thislength > maxlength)
                {
                    maxlength = thislength;
                    maxlrear = rear;
                    maxlfront = front;
                }
            }
            else
            {
                front = rear;
                thislength = 1;
                break;
            }
        }
    }
    while (maxlfront != maxlrear)
    {
        printf("%d ", maxlfront->data);
        maxlfront = maxlfront->next;
    }
    printf("%d\n", maxlfront->data);
    return;
}

int main()
{
    int n;
    scanf("%d", &n);
    List L;
    L = Read(n);
    MaxUpL(L);
    return 0;
}

