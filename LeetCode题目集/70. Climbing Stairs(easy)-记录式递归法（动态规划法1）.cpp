/*
 @Date    : 2019-02-17 21:31:39
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/climbing-stairs/
 */

static const int MAXN = 100005;
static int a[MAXN];

class Solution
{
public:
    int climbStairs(int n)
    {
        fill(a, a + MAXN, -1);
        a[1] = 1;
        a[2] = 2;
        a[3] = 3;
        return steps(n);
    }

    int steps(int n)
    {
        if (n > 0)
        {
            if (a[n] != -1)
            {
                return a[n];
            }
            else
            {
                int res = steps(n - 1) + steps(n - 2);
                a[n] = res;
                return res;
            }
        }
        return 0;
    }
};

