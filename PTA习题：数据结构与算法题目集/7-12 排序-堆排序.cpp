/*
 @Date    : 2018-03-13 10:35:50
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/720
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

static const int MAXN = 100001;

struct Heap
{
    int data[MAXN];
    int heapSize;
    Heap(int n): heapSize(n) {}
    int top();
    void pop();
    void percDown(int index);
    void build();
    void display();
};

int Heap::top()
{
    return data[1];
}

void Heap::percDown(int index)
{
    int x = data[index];
    int p, c;
    for (p = index; p * 2 <= heapSize; p = c)
    {
        c = p * 2;
        if (c + 1 <= heapSize && data[c + 1] > data[c])
            ++c;
        if (data[c] < x)
            break;
        else
            data[p] = data[c];
    }
    data[p] = x;
    return;
}

void Heap::pop()
{
    data[1] = data[heapSize--];
    percDown(1);
    return;
}

void Heap::build()
{
    for (int i = heapSize / 2; i != 0; --i)
    {
        percDown(i);
        // display();
    }
    return;
}

void Heap::display()
{
    printf("Now the heap is: \n");
    for (int i = 1; i != heapSize + 1; ++i)
        printf("%d ",data[i]);
    putchar('\n');
    return;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    vector<int> res;
    Heap H(N);
    for (int i = 1; i != N + 1; ++i)
        scanf("%d", &H.data[i]);
    // H.display();
    H.build();
    for (int i = 0; i != N; ++i)
    {
        res.push_back(H.top());
        H.pop();
    }
    int output = 0;
    for (auto it = res.rbegin(); it != res.rend(); ++it)
    {
        if (output++) putchar(' ');
        printf("%d", *it);
    }
    putchar('\n');

    return 0;
}

