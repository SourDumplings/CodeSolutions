/*
 @Date    : 2018-03-16 12:22:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/894
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXC = 2501;
static vector<int> courses[MAXC];

int my_hash(char name[])
{
    return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 +
    (name[2] - 'A')* 10 + (name[3] - '0');
}

void re_hash(int h, char name[])
{
    name[3] = h % 10 + '0';
    h /= 10;
    name[2] = h % 26 + 'A';
    h /= 26;
    name[1] = h % 26 + 'A';
    h /= 26;
    name[0] = h + 'A';
    name[4] = '\0';
    return;
}

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d\n", &N, &K);
    for (unsigned i = 0; i < N; ++i)
    {
        char name[5];
        scanf("%s", name);
        int C;
        scanf("%d", &C);
        for (unsigned j = 0; j < C; ++j)
        {
            int c;
            scanf("%d", &c);
            courses[c].push_back(my_hash(name));
        }
        getchar();
    }
    for (unsigned i = 1; i <= K; ++i)
    {
        printf("%d %d\n", i, courses[i].size());
        sort(courses[i].begin(), courses[i].end());
        char name[5];
        for (auto &nameI : courses[i])
        {
            re_hash(nameI, name);
            printf("%s\n", name);
        }
    }
    return 0;
}
