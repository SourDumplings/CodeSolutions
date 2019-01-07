/*
 @Date    : 2018-02-05 15:02:45
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1144
解答：

对于n对灯塔， 先把灯塔们按x坐标排序，然后观察y坐标中有多少逆序对
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

const int maxn = 4000001;

const int SZ = 1<<20;  //快速io
struct fastio{
    char inbuf[SZ];
    char outbuf[SZ];
    fastio(){
        setvbuf(stdin,inbuf,_IOFBF,SZ);
        setvbuf(stdout,outbuf,_IOFBF,SZ);
    }
}io;

struct LightHouse
{
    int x, y;
} data[maxn];

int cmpx(const void *a, const void *b)
{
    return ((LightHouse *)a)->x - ((LightHouse *)b)->x;
}

int cmpy(const void *a, const void *b)
{
    return ((LightHouse *)a)->y - ((LightHouse *)b)->y;
}

int binary_search(LightHouse A[], int l, int h, int value)
{
    while (l < h)
    {
        int mi = (l + h) >> 1;
        value < A[mi].y ? h = mi : l = mi + 1;
    }
    return --l;
}

long long calc_Inv_y(int start, int stop)
{
    if (stop - start < 2) return 0;
    int mid = (stop + start) >> 1;
    // printf("start = %d, stop = %d, mid = %d\n", start, stop, mid);
    long long cross = 0;
    LightHouse *temp = new LightHouse[mid-start];
    for (int i = start, count = 0; i != mid;)
        temp[count++] = data[i++];
    qsort(temp, mid-start, sizeof(temp[0]), cmpy);
    for (int i = mid; i != stop; ++i)
    {
        int j = binary_search(temp, 0, mid-start, data[i].y) + 1;
        cross += j;
    }
    delete [] temp;
    long long left = calc_Inv_y(start, mid);
    long long right = calc_Inv_y(mid, stop);
    // printf("left = %lld, right = %lld, cross = %lld\n", left, right, cross);
    return cross + left + right;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int X, Y;
    for (int i = 0; i != n; ++i)
    {
        scanf("%d %d", &X, &Y);
        data[i].x = X;
        data[i].y = Y;
    }
    qsort(data, n, sizeof(data[0]), cmpx);
    printf("%lld\n", calc_Inv_y(0, n));
    return 0;
}
