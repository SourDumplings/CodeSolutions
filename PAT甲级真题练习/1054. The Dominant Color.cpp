/*
 @Date    : 2018-01-28 16:36:54
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1054
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, M;
    scanf("%d %d", &N, &M);
    map<int, int> data;
    int c;
    int maxc, maxf = 0;
    for (int i = 0; i != N; ++i)
    {
        for (int j = 0; j != M; ++j)
        {
            scanf("%d", &c);
            ++data[c];
            if (data[c] > maxf)
            {
                maxf = data[c];
                maxc = c;
            }
        }
    }
    printf("%d\n", maxc);
    return 0;
}
