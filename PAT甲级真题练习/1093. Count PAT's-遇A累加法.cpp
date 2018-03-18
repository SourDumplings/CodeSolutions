/*
 @Date    : 2018-02-18 19:54:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1093
顺序扫描
每次遇到A，则将其前面的P数与后面的T数相乘，便得到由这个A构成的PAT数，累加即可。
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

static const int MOD = 1000000007;
static const int MAXL = 100001;

int main(int argc, char const *argv[])
{
    int P = 0;
    int res = 0;
    char str[MAXL];
    gets(str);
    int l = strlen(str);
    int T = count(str, str+l, 'T');
    for (int i = 0; i != l; ++i)
    {
        if (str[i] == 'P')
            ++P;
        else if (str[i] == 'A')
            res = (res + (P * T)) % MOD;
        else if (str[i] == 'T')
            --T;
    }
    printf("%d\n", res);
    return 0;
}
