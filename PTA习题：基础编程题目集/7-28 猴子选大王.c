#include <stdio.h>
#include <stdlib.h>

typedef struct monkey *ring;
struct monkey {
    int num;
    ring next;
};


int main()
{
    int N, i;
    ring f, r, temp, pr;

    f = (ring)malloc(sizeof(struct monkey));
    f->next = NULL;
    r = f;

    scanf("%d", &N);

    for (i = 1; i <= N; i++)
    {
        temp = (ring)malloc(sizeof(struct monkey));
        temp->num = i;
        temp->next = NULL;
        r->next = temp;
        r = temp;
        // printf("%d\n", r->num);
    }

    temp = f;
    f = f->next;
    free(temp);
    r->next = f;

    i = 1;
    r = f;
    while(r->next != r)
    {
        pr = r;
        r = r->next;
        i++;
        if(i == 3)
        {
            pr->next = r->next;
            temp = r;
            r = r->next;
            free(temp);
            i = 1;
        }
    }

    printf("%d\n", r->num);

    return 0;
}
