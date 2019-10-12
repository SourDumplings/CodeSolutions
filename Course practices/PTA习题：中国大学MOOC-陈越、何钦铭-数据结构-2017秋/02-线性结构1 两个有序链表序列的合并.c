#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

int data1[] = {1, 3, 5};
int data2[] = {2, 4, 6, 8};

List Merge( List L1, List L2 );

void Print(List L) {
  L = L->Next;
  if (L == NULL) {
    printf("NULL");
  }
  while (L != NULL) {
    printf("%d ", L->Data);
    L = L->Next;
  }
  printf("\n");
}

List Read() {
  static int state = 0;
  int *data, size, i;
  PtrToNode node = malloc(sizeof(struct Node));
  List head = node;
  node->Next = NULL;

  if (state == 0) {
    data = data1;
    size = sizeof(data1) / sizeof(int);
  } else {
    data = data2;
    size = sizeof(data2) / sizeof(int);
  }

  for (i = 0; i < size; ++i) {
    node->Next = malloc(sizeof(struct Node));
    node = node->Next;
    node->Data = data[i];
    node->Next = NULL;
  }

  state++;
  return head;
}

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    Print(L1);
    Print(L2);
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

// 按从小到大的顺序合并列表
List Merge( List L1, List L2 )
{
    List result, new, rear, t1, t2;
    result = (List)malloc(sizeof(struct Node));
    result->Next = NULL;
    rear = result;

    t1 = L1->Next;
    t2 = L2->Next;

    while(t1 && t2)
    {
        new = (List)malloc(sizeof(struct Node));
        if (t1->Data >= t2->Data)
        {
            new->Data = t2->Data;
            t2 = t2->Next;
        }
        else if (t1->Data < t2->Data)
        {
            new->Data = t1->Data;
            t1 = t1->Next;
        }
        new->Next = NULL;
        rear->Next = new;
        rear = new;
    }

    while(t1)
    {
        new = (List)malloc(sizeof(struct Node));
        new->Data = t1->Data;
        new->Next = NULL;
        rear->Next = new;
        rear = new;
        t1 = t1->Next;
    }
    while(t2)
    {
        new = (List)malloc(sizeof(struct Node));
        new->Data = t2->Data;
        new->Next = NULL;
        rear->Next = new;
        rear = new;
        t2 = t2->Next;
    }

    L1->Next = NULL;
    L2->Next = NULL;

    return result;
}
