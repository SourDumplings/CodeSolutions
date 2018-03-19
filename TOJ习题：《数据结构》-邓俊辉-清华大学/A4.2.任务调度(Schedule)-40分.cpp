/*
 @Date    : 2018-03-09 18:49:11
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1152
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int SZ = 1 << 22; //快速io
struct fastio {
    char inbuf[SZ];
    char outbuf[SZ];
    fastio() {
        setvbuf(stdin, inbuf, _IOFBF, SZ);
        setvbuf(stdout, outbuf, _IOFBF, SZ);
    }
} io;

int n, m;
// static const long long MAXF = pow(2, 32);
static const long long MAXF = static_cast<long long>(1) << 32;
static const int MAXN = 40001;
// static const int MAXN = 4000005;

struct Task
{
    char name[9];
    long long f;
    bool operator<(const Task &r);
    Task& operator=(const Task &r)
    {
        if (strcmp(r.name, name))
        {
            strcpy(name, r.name);
            f = r.f;
        }
        return *this;
    }
    Task(const Task &t): f(t.f)
    {
        strcpy(name, t.name);
    }
    Task(): f(0) { name[0] = '\0'; }
};

bool Task::operator<(const Task &r)
{
    if (f == r.f)
        return strcmp(name, r.name) > 0;
    return f > r.f;
}

struct Heap
{
    int heapSize;
    Task data[MAXN];
    Heap(int n): heapSize(n) {}
    void build();
    Task pop();
    void insert(Task t);
    void perc_down(int i);
};

void Heap::perc_down(int i)
{
    if (i * 2 > heapSize) return;
    int p, c;
    Task temp = data[i];
    for (p = i; p * 2 <= heapSize; p = c)
    {
        c = p * 2;
        if (c + 1 <= heapSize && data[c] < data[c+1])
            ++c;
        if (temp < data[c])
            data[p] = data[c];
        else
            break;
    }
    data[p] = temp;
    return;
}

void Heap::build()
{
    for (int i = heapSize; i != 0; --i)
        perc_down(i);
    return;
}

Task Heap::pop()
{
    Task res = data[1];
    data[1] = data[heapSize--];
    perc_down(1);
    return res;
}

void Heap::insert(Task t)
{
    data[++heapSize] = t;
    int c;
    for (c = heapSize; c >> 1 > 0 && data[c >> 1] < t; c >>= 1)
        data[c] = data[c >> 1];
    data[c] = t;
    return;
}

void print_heap(const Heap &H)
{
    printf("now heap is: ");
    for (int j = 1; j != H.heapSize + 1; ++j)
        printf("%s ", H.data[j].name);
    putchar('\n');
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    Heap H(n);
    for (int i = 1; i != n+1; ++i)
        scanf("%lld %s", &H.data[i].f, H.data[i].name);
    H.build();
    // print_heap(H);
    for (int i = 0; i != m && H.heapSize != 0; ++i)
    {
        Task t = H.pop();
        printf("%s\n", t.name);
        // print_heap(H);
        t.f *= 2;
        // printf("%lld %lld\n", t.f, MAXF);
        if (t.f < MAXF)
            H.insert(t);
    }
    return 0;
}

