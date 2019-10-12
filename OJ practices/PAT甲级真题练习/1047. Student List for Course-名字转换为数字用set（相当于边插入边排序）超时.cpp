/*
 @Date    : 2018-01-27 20:12:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1047
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int name2num(char name[])
{
    return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 +
    (name[2] - 'A') * 10 + (name[3] - '0');
}

void num2name(char name[], int num)
{
    name[3] = num % 10 + '0';
    num /= 10;
    name[2] = num % 26 + 'A';
    num /= 26;
    name[1] = num % 26 + 'A';
    num /= 26;
    name[0] = num % 26 + 'A';
    return;
}

struct Course
{
    set<int> students;
};

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);
    char name[5];
    int C, c;
    Course courseData[2501];
    for (int i = 0; i != N; ++i)
    {
        scanf("%s %d", name, &C);
        for (int j = 0; j != C; ++j)
        {
            scanf("%d", &c);
            courseData[c].students.insert(name2num(name));
        }
    }
    for (int i = 1; i <= K; ++i)
    {
        printf("%d %d\n", i, courseData[i].students.size());
        for (const auto id : courseData[i].students)
        {
            num2name(name, id);
            printf("%s\n", name);
        }
    }
    return 0;
}
