/*
 @Date    : 2018-08-28 20:18:57
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://pintia.cn/problem-sets/994805342720868352/problems/994805430595731456
 */

#include <iostream>
#include <cstdio>

using namespace std;

int N;

int main()
{
    cin >> N;
    int left, current, x = 1, right;
    int res = 0;
    while (N / x != 0)
    {
        right = N % x;
        left = N / (x * 10);
        current = (N - left * x * 10) / x;
        switch (current)
        {
        case 0:
            res += left * x; break;
        case 1:
            res += left * x + right + 1; break;
        default:
            res += (left + 1) * x; break;
        }
        x *= 10;
    }
    cout << res << endl;
    return 0;
}
