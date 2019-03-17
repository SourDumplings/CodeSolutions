/*
 @Date    : 2019-01-27 14:40:25
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/sqrtx/
 */

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
        {
            return 0;
        }
        long long lo = 1, hi = x;
        int ret;
        while (true)
        {
            long long mi = (lo + hi) >> 1;
            if (mi * mi <= x)
            {
                if ((mi + 1) * (mi + 1) > x)
                {
                    ret = mi;
                    break;
                }
                else
                    lo = mi;
            }
            else
                hi = mi;
        }
        return ret;
    }
};

