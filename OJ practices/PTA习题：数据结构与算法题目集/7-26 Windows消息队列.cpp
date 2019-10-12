/*
 @Date    : 2018-03-14 09:00:20
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/15/problems/841
用string会超时
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct Msg
{
    char msg[11];
    int f;
};

bool operator<(const Msg &m1, const Msg &m2)
{
    return m1.f > m2.f;
}

int main(int argc, char const *argv[])
{
    int N;
    scanf("%d", &N);
    priority_queue<Msg> Q;
    while (N--)
    {
        char op[10];
        scanf("%s", op);
        if (op[0] == 'P')
        {
            char msg[11];
            int f;
            scanf("%s %d", msg, &f);
            Msg m; m.f = f; strcpy(m.msg, msg);
            Q.push(m);
        }
        else
        {
            if (!Q.empty())
            {
                printf("%s\n", Q.top().msg); Q.pop();
            }
            else
                printf("EMPTY QUEUE!\n");
        }
    }
    return 0;
}

