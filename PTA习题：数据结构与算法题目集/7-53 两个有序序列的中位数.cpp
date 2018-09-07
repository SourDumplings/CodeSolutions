/*
 @Date    : 2018-03-17 11:00:51
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/3001
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> v;
    int N;
    scanf("%d", &N);
    for (unsigned i = 0; i < N; ++i)
    {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    for (unsigned i = 0; i < N; ++i)
    {
        int num;
        scanf("%d", &num);
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    printf("%d\n", v[(2 * N + 1) / 2 - 1]);
    return 0;
}

