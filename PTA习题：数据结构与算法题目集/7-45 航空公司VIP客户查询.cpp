/*
 @Date    : 2018-03-16 09:40:57
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/892
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <unordered_map>

using namespace std;

int main(int argc, char const *argv[])
{
    int N, K;
    scanf("%d %d", &N, &K);
    unordered_map<string, int> data;
    for (unsigned i = 0; i < N; ++i)
    {
        char id[19];
        int k;
        scanf("%s %d", id, &k);
        if (k < K) k = K;
        data[string(id)] += k;
    }
    int M;
    scanf("%d", &M);
    for (unsigned i = 0; i < M; ++i)
    {
        char id[19];
        scanf("%s", id);
        if (data.find(string(id)) == data.end())
        {
            printf("No Info\n");
        }
        else
        {
            printf("%d\n", data[string(id)]);
        }
    }
    return 0;
}

