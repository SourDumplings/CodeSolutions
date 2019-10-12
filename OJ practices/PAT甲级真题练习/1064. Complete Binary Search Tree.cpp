/*
 @Date    : 2018-02-03 12:02:52
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://www.patest.cn/contests/pat-a-practise/1064
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1010;

int level[maxn]; // 层序遍历序列，下标从1开始
int In[maxn];
int p = 0;
int n;


void InOrderTraversal(int root)
{
    if (root <= n)
    {
        InOrderTraversal(2*root);
        level[root] = In[p++];
        InOrderTraversal(2*root+1);
    }
    return;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 0; i != n; ++i)
        scanf("%d", &In[i]);
    sort(In, In+n);
    InOrderTraversal(1);
    int output = 0;
    for (int i = 1; i != n + 1; ++i)
    {
        if (output++)
            putchar(' ');
        printf("%d", level[i]);
    }
    putchar('\n');
    return 0;
}
