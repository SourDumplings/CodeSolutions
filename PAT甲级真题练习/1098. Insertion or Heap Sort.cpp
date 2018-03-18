/*
 @Date    : 2018-02-20 19:51:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1098
注意判断下一个insertion sort所取元素的方法，不能从后往前扫描来找第一个
与原序列不等的元素作为insertion sort完成序列的末尾元素，
因为有可能原序列前几个元素就是有序的
比如原序列：124867
现在的序列：124867
从后往前扫描法找不同便找不出insertion sort的进度了
按照题意的单解性，应该认为下一个要插入的元素为6
因此要用从前往后扫描找第一个破坏有序的元素作为下一个要插入的元素
 */

#include <iostream>
#include <cstdio>

using namespace std;

static const int MAXN = 101;
static int origin[MAXN];
static int now[MAXN];
static int flag;

char judge(int N)
{
    int i;
    // 排除前几个元素相等的情况
    for (i = 0; i < N - 1 && now[i] == now[i+1]; i++);
    return now[i] < now[i+1] ? 'I' : 'H';
}

void next_insertion(int N)
{
    int i;
    // 找出第一个破坏有序性的元素now[i+1]
    for (i = 0; i != N && now[i] <= now[i+1]; ++i);
    flag = i;
    printf("Insertion Sort\n");
    int p = origin[flag+1];
    for (i = flag; i != -1 && now[i] > p; --i)
        now[i+1] = now[i];
    now[i+1] = p;
    return;
}

void perc_down_heap(int parent, int n)
{
    int x = now[parent];
    int p, c;
    for (p = parent; p * 2 + 1 < n; p = c)
    {
        c = p * 2 + 1;
        if (c < n - 1 && now[c+1] > now[c])
            ++c;
        if (x < now[c])
            now[p] = now[c];
        else
            break;
    }
    now[p] = x;
    return;
}

void next_heap(int N)
{
    printf("Heap Sort\n");
    int i;
    for (i = 1; i != N && now[i] < now[0]; ++i);
    swap(now[0], now[i-1]);
    perc_down_heap(0, i-1);
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
        scanf("%d", &origin[i]);
    for (int i = 0; i != N; ++i)
        scanf("%d", &now[i]);
    char j = judge(N);
    switch (j)
    {
        case 'I' : next_insertion(N); break;
        case 'H' : next_heap(N); break;
    }
    int output = 0;
    for (int i = 0; i != N; ++i)
    {
        if (output++)
            putchar(' ');
        printf("%d", now[i]);
    }
    putchar('\n');
    return 0;
}
