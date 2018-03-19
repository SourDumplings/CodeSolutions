/*
 @Date    : 2018-03-04 13:51:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1149
TOJ 上得到的结果：
Case No.    Result  Time(ms)    Memory(KB)
1   Accepted    0   13412
2   Accepted    0   13408
3   Accepted    0   13412
4   Accepted    0   13408
5   Accepted    0   13404
6   Accepted    0   13412
7   Accepted    0   13408
8   Accepted    0   13408
9   Runtime Error (signal 11)   0   ≥13028
10  Accepted    0   13404
11  Accepted    0   13412
12  Accepted    0   13408
13  Accepted    20  13412
14  Runtime Error (signal 11)   0   ≥13144
15  Time Limit Exceeded ≥10996  20680
16  Runtime Error (signal 11)   408 ≥20500
17  Runtime Error (signal 11)   28  ≥13612
18  Runtime Error (signal 11)   16  ≥13612
19  Runtime Error (signal 11)   28  ≥13608
20  Time Limit Exceeded ≥11000  20660
把free_tree函数去掉测试点16可过，实在是检查不出哪里出问题了
 */

#include <iostream>
#include <cstdio>
#include "temperature.h"
// #include "temperature_lib.c"
#include <cstdlib>
#include <cstring>

#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

using namespace std;

enum Direction { VERTICAL, HORIZONTAL };

struct PosType
{
    int x, y;
    PosType() = default;
    PosType(int x_, int y_): x(x_), y(y_) {}
};

struct KDtreeNode
{
    Direction splitDirection;
    PosType splitLine;
    KDtreeNode *left = nullptr, *right = nullptr;
    PosType leftDown, rightUp;
    virtual ~KDtreeNode() = default;
};

struct KDtreeLeafNode: public KDtreeNode
{
    int data;
    virtual ~KDtreeLeafNode() = default;
};

static const int MAXN = 50001;

KDtreeNode* create_leaf(int station)
{
    KDtreeLeafNode *leaf = new KDtreeLeafNode();
    GetStationInfo(station, &leaf->leftDown.x, &leaf->leftDown.y, &leaf->data);
    leaf->rightUp = leaf->leftDown;
    return leaf;
}

int cmp_x(const void *a, const void *b)
{
    int xa, xb;
    int tempy, temp;
    GetStationInfo((*(int *)a), &xa, &tempy, &temp);
    GetStationInfo((*(int *)b), &xb, &tempy, &temp);
    return xa - xb;
}

int cmp_y(const void *a, const void *b)
{
    int ya, yb;
    int tempx, temp;
    GetStationInfo((*(int *)a), &tempx, &ya, &temp);
    GetStationInfo((*(int *)b), &tempx, &yb, &temp);
    return ya - yb;
}

PosType find_median(Direction direction, int P[], int p)
{
    int tempP[p];
    memcpy(tempP, P, p * sizeof(int));
    if (direction == VERTICAL)
        qsort(tempP, p, sizeof(tempP[0]), cmp_y);
    else
        qsort(tempP, p, sizeof(tempP[0]), cmp_x);
    int medianPos = tempP[(p-1)/2], useless;
    PosType temp;
    GetStationInfo(medianPos, &temp.x, &temp.y, &useless);
    return temp;
}

void divide(int P[], int p, Direction direction, PosType splitLine,
    int Pl[], int &lp, int Pr[], int &rp)
{
    int temp, useless;
    if (direction == VERTICAL)
    {
        int y;
        for (int i = 0; i != p; ++i)
        {
            GetStationInfo(P[i], &temp, &y, &useless);
            if (y <= splitLine.y)
                Pl[lp++] = P[i];
            else
                Pr[rp++] = P[i];
        }
    }
    else
    {
        int x;
        for (int i = 0; i != p; ++i)
        {
            GetStationInfo(P[i], &x, &temp, &useless);
            if (x <= splitLine.x)
                Pl[lp++] = P[i];
            else
                Pr[rp++] = P[i];
        }
    }
    return;
}

KDtreeNode* build_kdTree(int P[], int p, int d)
{
    if (p == 0) return nullptr;
    if (p == 1) return create_leaf(P[0]);
    KDtreeNode *root = new KDtreeNode();
    root->splitDirection = ((d & 1) == 0 ? VERTICAL : HORIZONTAL);
    root->splitLine = find_median(root->splitDirection, P, p);
    int Pl[p], Pr[p];
    int lp = 0, rp = 0;
    divide(P, p, root->splitDirection, root->splitLine, Pl, lp, Pr, rp);
    root->left = build_kdTree(Pl, lp, d+1);
    root->right = build_kdTree(Pr, rp, d+1);
    root->leftDown.x = min(root->left->leftDown.x, root->right->leftDown.x);
    root->leftDown.y = min(root->left->leftDown.y, root->right->leftDown.y);
    root->rightUp.x = max(root->left->rightUp.x, root->right->rightUp.x);
    root->rightUp.y = max(root->left->rightUp.y, root->right->rightUp.y);
    return root;
}

bool inside(const KDtreeNode *T, const PosType &leftDown, const PosType &rightUp)
{
    return T->leftDown.x >= leftDown.x && T->leftDown.y >= leftDown.y &&
    T->rightUp.x <= rightUp.x && T->rightUp.y <= rightUp.y;
}

bool cross(const KDtreeNode *T, const PosType &leftDown, const PosType &rightUp)
{
    bool isCross = true;
    if (inside(T, leftDown, rightUp) ||
        (T->leftDown.y > rightUp.y || T->rightUp.x < leftDown.x ||
        T->leftDown.x > rightUp.x || T->rightUp.y < leftDown.y))
        isCross = false;
    return isCross;
}

void report(const KDtreeNode *T, long long &res, int &count)
{
    const KDtreeNode *Q[MAXN];
    int front = 0, back = 0;
    Q[back++] = T;
    while (front != back)
    {
        const KDtreeNode *temp = Q[front++];
        if (temp->left || temp->right)
        {
            if (temp->left) Q[back++] = temp->left;
            if (temp->right) Q[back++] = temp->right;
        }
        else
        {
            // printf("(%d, %d) = %d has added\n",
                // temp->leftDown.x, temp->leftDown.y, temp->data);
            res += dynamic_cast<const KDtreeLeafNode*>(temp)->data;
            ++count;
        }
    }
    return;
}

void kd_search(const KDtreeNode *T, const PosType &leftDown, const PosType &rightUp,
    long long &res, int &count)
{
    if (!T) return;
    if (T->left == nullptr && T->right == nullptr)
    {
        if (inside(T, leftDown, rightUp)) report(T, res, count);
        return;
    }
    if (T->left)
    {
        if (inside(T->left, leftDown, rightUp)) report(T->left, res, count);
        else if (cross(T->left, leftDown, rightUp))
            kd_search(T->left, leftDown, rightUp, res, count);
    }
    if (T->right)
    {
        if (inside(T->right, leftDown, rightUp)) report(T->right, res, count);
        else if (cross(T->right, leftDown, rightUp))
            kd_search(T->right, leftDown, rightUp, res, count);
    }
    return;
}

void free_tree(KDtreeNode *T)
{
    if (!T) return;
    KDtreeNode *Q[MAXN];
    int front = 0, back = 0;
    Q[back++] = T;
    while (back != front)
    {
        KDtreeNode *temp = Q[front++];
        if (temp->left) Q[back++] = temp->left;
        if (temp->right) Q[back++] = temp->right;
        delete temp;
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n = GetNumOfStation();
    int P[n];
    for (int i = 0; i != n; ++i) P[i] = i;
    KDtreeNode *T = build_kdTree(P, n, 0);
    int x1, x2, y1, y2;
    while (GetQuery(&x1, &y1, &x2, &y2))
    {
        long long res = 0;
        int count = 0;
        PosType leftDown(x1, y1), rightUp(x2, y2);
        // printf("\nQuery: (%d %d) (%d %d)\n", leftDown.x, leftDown.y, rightUp.x, rightUp.y);
        kd_search(T, leftDown, rightUp, res, count);
        if (count) Response(res/count);
        else Response(0);
    }
    free_tree(T);
    return 0;
}

