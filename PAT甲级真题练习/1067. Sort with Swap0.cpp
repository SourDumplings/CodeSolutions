/*
 @Date    : 2018-02-06 17:41:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1067
包含零的多元环交换次数ni-1，不包含0的为ni+1(先把0交换进去再进行n-1次交换再把0换出来)，
单元环不用交换（即已经就位的元素）
序列中包含K个多元环，S个单元环
总数就是K个多元环所需交换次数之和，或者是N-S+K-2
 */

#include <cstdio>

using namespace std;

const int maxn = 100001;

int main(int argc, char const *argv[])
{
    int n;
    int A[maxn];
    scanf("%d", &n);
    bool checked[maxn];
    int count = 0;
    for (int i = 0; i != n; ++i)
    {
        scanf("%d", &A[i]);
        checked[i] = false;
    }
    for (int i = 0; i != n; ++i)
    {
        if (!checked[i])
        {
            int ni = 0;
            int next = i;
            bool includeZero = false;
            do
            {
                checked[next] = true;
                if (next == 0)
                    includeZero = true;
                ++ni;
                next = A[next];
            } while (A[next] != A[i]);
            if (ni > 1)
            {
                if (includeZero)
                    count += ni - 1;
                else
                    count += ni + 1;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
