/*
 @Date    : 2018-02-18 19:44:29
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1093
顺序扫描
每次遇到一个T则将此时PAT的个数和此时的PA的个数相加，便得到此时的PAT的个数
每次遇到一个A则将此时PA的个数和此时的P的个数相加，便得到此时的PA个数
每次遇到一个P则当前P的个数加1
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MOD = 1000000007;
static const int MAXL = 100001;

int main(int argc, char const *argv[])
{
    int P = 0, PA = 0, PAT = 0;
    char str[MAXL];
    gets(str);
    int l = strlen(str);
    for (int i = 0; i != l; ++i)
    {
        if (str[i] == 'P')
            ++P;
        else if (str[i] == 'A')
            PA = (PA + P) % MOD;
        else if (str[i] == 'T')
            PAT = (PAT + PA) % MOD;
    }
    printf("%d\n", PAT);
    return 0;
}
