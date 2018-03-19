/*
 @Date    : 2018-03-06 20:26:43
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1150
 */

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

static const int MAXS = 41;
static const int M = 26 * 26 * 26 * 26 * 2;
static char data[M][MAXS];
static bool outputed[M];

int my_pow(int b, int e)
{
    int res = 1;
    for (int i = 0; i != e; ++i)
        res *= b;
    return res;
}

int my_hash(char name[])
{
    int h = (name[0] - 'a') * my_pow(26, 3);
    if (name[1] != '\0')
    {
        h += (name[1] - 'a') * my_pow(26, 2);
        if (name[2] != '\0')
        {
            h += (name[2] - 'a') * my_pow(26, 1);
            if (name[3] != '\0')
                h += name[3] - 'a';
        }
    }
    return h;
}

int my_find(char name[])
{
    int h = my_hash(name);
    int pos;
    for (pos = h; data[pos][0] != '\0' && strcmp(data[pos], name); pos = (pos + 1) % M);
    return pos;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i != M; ++i)
    {
        outputed[i] = false;
        data[i][0] = '\0';
    }
    for (int i = 0; i != N; ++i)
    {
        char name[MAXS];
        scanf("%s", name);
        int pos = my_find(name);
        if (strcmp(data[pos], name) == 0)
        {
            if (!outputed[pos])
            {
                printf("%s\n", data[pos]);
                outputed[pos] = true;
            }
        }
        else
            strcpy(data[pos], name);
    }
    return 0;
}

