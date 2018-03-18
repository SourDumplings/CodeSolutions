/*
 @Date    : 2018-03-05 08:41:31
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1128
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K, r;
    scanf("%d", &K);
    while (K--)
    {
        scanf("%d", &N);
        int row[N];
        bool ok = true;
        for (int i = 0; i != N; ++i)
        {
            scanf("%d", &row[i]);
            if (ok)
            {
                for (int j = 0; j != i; ++j)
                {
                    if (row[i] == row[j] || abs(row[i] - row[j]) == abs(i - j))
                    {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}

