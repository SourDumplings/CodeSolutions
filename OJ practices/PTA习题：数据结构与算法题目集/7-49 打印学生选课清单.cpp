/*
 @Date    : 2018-03-16 20:00:21
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/896
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    vector<int> courses;
};

static const int MAXN = 26 * 26 * 26 *10;
static Student S[MAXN];
static int N, K;

int my_hash(char name[])
{
    return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 +
    (name[2] - 'A') * 10 + (name[3] - '0');
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &N, &K);
    for (unsigned i = 0; i < K; ++i)
    {
        int c, k;
        scanf("%d %d", &c, &k);
        for (unsigned j = 0; j < k; ++j)
        {
            char name[10];
            scanf("%s", name);
            int h = my_hash(name);
            S[h].courses.push_back(c);
        }
    }
    for (unsigned i = 0; i < N; ++i)
    {
        char name[10];
        scanf("%s", name);
        printf("%s %d", name, S[my_hash(name)].courses.size());
        sort(S[my_hash(name)].courses.begin(), S[my_hash(name)].courses.end());
        for (auto &c : S[my_hash(name)].courses)
        {
            printf(" %d", c);
        }
        putchar('\n');
    }
    return 0;
}

