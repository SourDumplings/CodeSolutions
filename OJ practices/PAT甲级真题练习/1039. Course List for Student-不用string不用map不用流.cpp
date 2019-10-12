/*
 @Date    : 2018-01-27 19:39:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1039
 */

#include <cstdio>
#include <set>

using namespace std;

int name2num(char *name)
{
    return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10
           + (name[2] - 'A') * 10 + name[3] - '0';
}

struct Student
{
    set<int> courses;
} data[26*26*26*10];

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);
    int c, Ni;
    char name[5];
    for (int i = 0; i != K; ++i)
    {
        scanf("%d %d", &c, &Ni);
        for (int i = 0; i != Ni; ++i)
        {
            scanf("%s", name);
            data[name2num(name)].courses.insert(c);
        }
    }
    int id;
    for (int i = 0; i != N; ++i)
    {
        scanf("%s", name);
        id = name2num(name);
        printf("%s %d", name, data[id].courses.size());
        for (auto c : data[id].courses)
        {
            printf(" %d", c);
        }
        putchar('\n');
    }
    return 0;
}
