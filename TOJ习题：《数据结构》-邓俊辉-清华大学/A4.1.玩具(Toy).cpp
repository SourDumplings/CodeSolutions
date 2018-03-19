/*
 @Date    : 2018-03-09 13:58:53
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1151
一共有8!=40320中状态，通过哈希表建立映射(康托展开)。
大体思路就是从原始状态开始通过三种操作的反向给出一切可以达到的状态，
通过BFS进行探索。
如果某个状态已经实现过则回溯，因为BFS第一遍到达该结点的步数就是最短路径
故需要记录每个状态的访问标记和需要达到的最小步数，假设步数为-1即为未访问过。
对于逆康托要保存康托的结果，大大提高效率
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MAX = 40321;

static const int factorial[8] = {1, 1, 2, 6, 24, 120, 720, 5040};

struct stateInfo
{
    bool valid = false;
    int A[8];
    int step = -1;
};

static stateInfo data[MAX];

struct Queue
{
    int data[MAX];
    int front = 0, end = 0;
    int pop()
    {
        int temp = front;
        front = (front + 1) % MAX;
        return data[temp];
    }
    void push(int i)
    {
        data[end] = i;
        end = (end + 1) % MAX;
        return;
    }
    bool empty() { return front == end; }
};

template <typename T>
void print(T A[], int n)
{
    for (int i = 0; i != n; ++i)
        cout << A[i] << ' ';
    putchar('\n');
    return;
}

void check_enq(int w, int v, Queue &Q)
{
    if (data[w].step == -1)
    {
        data[w].step = data[v].step + 1;
        Q.push(w);
    }
    return;
}

int contor(int A[], int n)
{
    int res = 0;
    for (int i = 0; i != n; ++i)
    {
        int smaller = 0;
        for (int j = i + 1; j != n; ++j)
        {
            if (A[j] < A[i]) ++smaller;
        }
        res += smaller * factorial[n-i-1];
    }
    return res;
}

void re_contor(int stateNo, int n)
{
    int temp;
    bool used[n];
    memset(used, false, sizeof(used));
    int tempStateNo = stateNo;
    for (int i = 0; i != n - 1; ++i)
    {
        temp = tempStateNo / factorial[n-i-1];
        int rank = 0;
        for (int j = 1; j != n + 1; ++j)
        {
            if (!used[j-1])
                ++rank;
            if (rank == temp + 1)
            {
                data[stateNo].A[i] = j;
                used[j-1] = true;
                break;
            }
        }
        tempStateNo %= factorial[n-i-1];
    }
    for (int i = 0; i != n; ++i)
    {
        if (!used[i])
        {
            data[stateNo].A[n-1] = i + 1;
            break;
        }
    }
    data[stateNo].valid = true;
    return;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    return;
}

// 上下互换
int op1(int A_o[])
{
    int A[8];
    memcpy(A, A_o, sizeof(A));
    swap(A[0], A[7]);
    swap(A[1], A[6]);
    swap(A[2], A[5]);
    swap(A[3], A[4]);
    int res = contor(A, 8);
    memcpy(data[res].A, A, sizeof(A));
    data[res].valid = true;
    return res;
}

// 循环左移
int op2(int A_o[])
{
    int A[8];
    memcpy(A, A_o, sizeof(A));
    int temp1 = A[0], temp2 = A[7];
    A[0] = A[1];
    A[1] = A[2];
    A[2] = A[3];
    A[7] = A[6];
    A[6] = A[5];
    A[5] = A[4];
    A[3] = temp1;
    A[4] = temp2;
    int res = contor(A, 8);
    memcpy(data[res].A, A, sizeof(A));
    data[res].valid = true;
    return res;
}

// 逆时针旋转
int op3(int A_o[])
{
    int A[8];
    memcpy(A, A_o, sizeof(A));
    int temp = A[1];
    A[1] = A[2];
    A[2] = A[5];
    A[5] = A[6];
    A[6] = temp;
    int res = contor(A, 8);
    memcpy(data[res].A, A, sizeof(A));
    data[res].valid = true;
    return res;
}

void BFS()
{
    Queue Q;
    Q.push(0);
    data[0].step = 0;
    while (!Q.empty())
    {
        int v = Q.pop();
        if (!data[v].valid) re_contor(v, 8);
        // printf("reached stateNo = %d: ", v);
        // print(data[v].A, 8);
        int w1 = op1(data[v].A), w2 = op2(data[v].A), w3 = op3(data[v].A);
        check_enq(w1, v, Q);
        check_enq(w2, v, Q);
        check_enq(w3, v, Q);
    }
    return;
}

int main(int argc, char const *argv[])
{
    BFS();
    int N;
    scanf("%d", &N);
    for (int i = 0; i != N; ++i)
    {
        int A[8];
        for (int j = 0; j != 8; ++j) scanf("%d", &A[j]);
        int stateNo = contor(A, 8);
        // printf("stateNo = %d for A: \n", stateNo);
        // print(A, 8);
        printf("%d\n", data[stateNo].step);
    }
    return 0;
}

