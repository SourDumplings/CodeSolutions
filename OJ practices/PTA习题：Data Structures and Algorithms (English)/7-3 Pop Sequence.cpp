/*
 @Date    : 2018-09-07 16:52:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/16/problems/665
 */

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int M, N, K;

bool check(int seq[])
{
    stack<int> S;
    bool ret = true;
    int nowNum = 1;
    for (int i = 0; i != N; ++i)
    {
        if (S.empty() || S.top() != seq[i])
        {
            if (!S.empty() && seq[i] < S.top())
            {
                ret = false;
                break;
            }
            else
            {
                while (true)
                {
                    S.push(nowNum++);
                    if (S.top() == seq[i] || S.size() == M)
                        break;
                }
                if (S.top() != seq[i])
                {
                    ret = false;
                    break;
                }
                else
                    S.pop();
            }
        }
        else if (S.top() == seq[i])
            S.pop();
    }
    return ret;
}

int main()
{
    scanf("%d %d %d", &M, &N, &K);
    while (K--)
    {
        int seq[N];
        for (int i = 0; i != N; ++i)
            scanf("%d", &seq[i]);
        if (check(seq))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
