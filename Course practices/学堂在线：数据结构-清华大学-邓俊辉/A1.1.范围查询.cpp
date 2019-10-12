/*
 @Date    : 2018-02-01 11:38:35
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/course.shtml?courseid=58
 */

#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAXN = 500001;

int BiSearch(const int num[], int lo, int hi, int value)
{
    int mi;
    while (lo < hi)
    {
        mi = (hi + lo) >> 1;
        value < num[mi] ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

void SearchAndCount(const int num[], const int n, const int low, const int up)
{
    int low_pos = BiSearch(num, 0, n, low);
    int up_pos = BiSearch(num, low_pos, n, up);
    // printf("low_pos = %d, up_pos = %d\n", low_pos, up_pos);
    int count = 0;
    if (num[low_pos] == low)
    {
        for (int i = low_pos; i != -1 && num[i] == low; --i)
            ++count;
    }
    count += up_pos - low_pos;
    printf("%d\n", count);
    return;
}

int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main(int argc, char const *argv[])
{
    int num[MAXN];
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i != n; ++i)
        scanf("%d", &num[i]);
    qsort(num, n, sizeof(num[0]), cmp);
    int low, up;
    while (m--)
    {
        scanf("%d %d", &low, &up);
        SearchAndCount(num, n, low, up);
    }
    return 0;
}
