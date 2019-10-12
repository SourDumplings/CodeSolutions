/*
 @Date    : 2019-01-05 22:05:14
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/1071785408849047552
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int N;
const int MAXN = 1005;
int T[MAXN];
int heap = -1, lastCheck = -2;
vector<int> path;

void print_path()
{
    int output = 0, lastN = -1;
    for (int n : path)
    {
        if (heap != 0)
        {
            if (lastN != -1)
            {
                if (n > lastN)
                {
                    if (lastCheck == 1)
                        heap = 0;
                    else
                        lastCheck = -1;
                }
                else if (n < lastN)
                {
                    if (lastCheck == -1)
                        heap = 0;
                    else
                        lastCheck = 1;
                }
            }
        }
        lastN = n;
        if (output++)
            putchar(' ');
        printf("%d", n);
    }
    if (heap != 0)
    {
        heap = lastCheck;
    }
    putchar('\n');
    return;
}

void dfs(int r)
{
    path.push_back(T[r]);
    if (r * 2 > N)
        print_path();
    else
    {
        if (2 * r + 1 <= N)
            dfs(2 * r + 1);
        dfs(2 * r);
    }
    path.pop_back();
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &N);
    for (int i = 1; i < N + 1; ++i)
    {
        scanf("%d", &T[i]);
    }
    dfs(1);
    if (heap == -1)
        printf("Min Heap\n");
    else if (heap == 0)
        printf("Not Heap\n");
    else
        printf("Max Heap\n");
    return 0;
}

