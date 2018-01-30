#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node));
        scanf("%d", &p->Data);
        p->Next = L;  L = p;
    }
    printf("%d\n", FactorialSum(L));

    return 0;
}


int FactorialSum( List L )
{
    int result = 0, product = 1;
    int num, i;

    while (L)
    {
        num = L->Data;
        for (i = 1; i <= num; i++)
        {
            product *= i;
        }
        result += product;
        product = 1;
        L = L->Next;
    }
    return result;

}
