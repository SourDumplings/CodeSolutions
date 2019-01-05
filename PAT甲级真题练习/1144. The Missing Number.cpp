/*
 @Date    : 2018-08-06 21:40:56
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805343463260160
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    bool h[100002];
    fill(h, h + 100002, false);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
    {
        int num;
        scanf("%d", &num);
        if (num > 0 && num < 100002)
        {
            h[num] = true;
        }
    }
    for (unsigned i = 1; i < 100002; ++i)
    {
        if (!h[i])
        {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}
