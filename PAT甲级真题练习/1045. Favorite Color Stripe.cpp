/*
 @Date    : 2018-08-27 22:44:05
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805437411475456
 */

#include <iostream>
#include <cstdio>

using namespace std;

int N, M, L;
const int MAXL = 10005, MAXM = 205;
int l[MAXL], m[MAXM];
int maxL[MAXM][MAXL];

int main()
{
    for (int i = 0; i != MAXM; ++i)
    {
        for (int j = 0; j != MAXL; ++j)
            maxL[i][j] = 0;
    }

    scanf("%d %d", &N, &M);
    for (int i = 1; i != M + 1; ++i)
        scanf("%d", &m[i]);
    scanf("%d", &L);
    for (int i = 1; i != L + 1; ++i)
        scanf("%d", &l[i]);

    for (int i = 1; i != M + 1; ++i)
    {
        for (int j = 1; j != L + 1; ++j)
            maxL[i][j] = maxL[i-1][j];
        int c = m[i];
        for (int j = 1; j != L + 1; ++j)
        {
            int temp = max(maxL[i-1][j], maxL[i][j-1]);
            if (l[j] == c)
                maxL[i][j] = temp + 1;
            else
                maxL[i][j] = temp;
        }
    }
    printf("%d\n", maxL[M][L]);

    return 0;
}


