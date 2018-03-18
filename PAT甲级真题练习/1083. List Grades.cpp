/*
 @Date    : 2018-02-16 11:51:47
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1083
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Student
{
    char id[11], name[11];
    int grade;
};

int my_find(const vector<Student> &data, int g)
{
    int lo = 0, hi = data.size();
    while (lo < hi)
    {
        int mi = (lo + hi) >> 1;
        g < data[mi].grade ? hi = mi : lo = mi + 1;
    }
    return --lo;
}

int main(int argc, char const *argv[])
{
    vector<Student> data;
    int N;
    scanf("%d", &N);
    while (N--)
    {
        Student S;
        scanf("%s %s %d", S.name, S.id, &S.grade);
        data.push_back(S);
    }
    sort(data.begin(), data.end(),
        [] (const Student &s1, const Student &s2) { return s1.grade < s2.grade; });
    int g1, g2;
    scanf("%d %d", &g1, &g2);
    int b = my_find(data, g1), e = my_find(data, g2);
    if (data[b].grade < g1)
        ++b;
    if (b == data.size())
        printf("NONE\n");
    else
    {
        for (int i = e;; --i)
        {
            printf("%s %s\n", data[i].name, data[i].id);
            if (i == b)
                break;
        }
    }
    return 0;
}
