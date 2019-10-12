#include <stdio.h>
#include <string.h>

struct tong{
    char name[11];
    char birthday[11];
    char sex;
    char gnum[17];
    char num[17];
};

void input();
void output();

int main()
{
    int n;
    scanf("%d", &n);
    struct tong t[n];
    input(t, n);
    output(t, n);

    return 0;
}

void input(struct tong p[], int n)
{
    int i;
    for(i = 0; i < n; i++) {
        scanf("%s %s %c %s %s", p[i].name, p[i].birthday, &p[i].sex, p[i].gnum, p[i].num);
        }

}

void output(struct tong q[], int n)
{
    int m, j;
    scanf("%d", &m);
    int a[m];
    for(j = 0; j < m; j++) {
        scanf("%d", &a[j]);
    }
    for(j = 0; j < m; j++) {
        if(a[j] >=0 && a[j] < n) {
            printf("%s %s %s %c %s\n", q[a[j]].name, q[a[j]].gnum, q[a[j]].num, q[a[j]].sex, q[a[j]].birthday);
        }
        else {
            printf("Not Found\n");
        }
    }
}
