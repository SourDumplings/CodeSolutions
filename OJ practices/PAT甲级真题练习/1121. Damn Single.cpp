/*
 @Date    : 2018-03-01 20:31:04
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1121
如果没有单身狗在输出0之后不能输出空行
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

static const int MAX = 100000;
static int couple[MAX];

int main(int argc, char const *argv[])
{
    fill(couple, couple+MAX, -1);
    int N, M;
    scanf("%d", &N);
    int id1, id2;
    while (N--)
    {
        scanf("%d %d", &id1, &id2);
        couple[id1] = id2;
        couple[id2] = id1;
    }
    scanf("%d", &M);
    set<int> guests;
    while (M--)
    {
        scanf("%d", &id1);
        guests.insert(id1);
    }
    vector<int> singles;
    for (int i : guests)
    {
        if (couple[i] == -1 || guests.find(couple[i]) == guests.end())
            singles.push_back(i);
    }
    printf("%d\n", singles.size());
    int output = 0;
    for (int i : singles)
    {
        if (output++) putchar(' ');
        printf("%05d", i);
    }
    if (output) putchar('\n');
    return 0;
}
