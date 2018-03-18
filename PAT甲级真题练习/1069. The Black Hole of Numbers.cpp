/*
 @Date    : 2018-02-07 13:48:00
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1069
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool same(const char s[])
{
    char c = s[0];
    for (int i = 0; i != 4; ++i)
    {
        if (s[i] != c)
            return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    char f[5], r[5];
    sprintf(f, "%04d", N);
    if (same(f))
        printf("%04d - %04d = 0000\n", N, N);
    else
    {
        int result;
        do
        {
            sort(f, f+4);
            reverse_copy(f, f+4, r);
            r[4] = '\0';
            result = stoi(string(r))-stoi(string(f));
            printf("%s - %s = %04d\n", r, f, result);
            sprintf(f, "%04d", result);
        } while (result != 6174);
    }

    return 0;
}
