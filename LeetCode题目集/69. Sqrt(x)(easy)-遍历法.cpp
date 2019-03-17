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
        int ret;
        for (int i = 0; i <= x; ++i)
        {
            if (i * i <= x && ((long long)(i + 1) * (long long)(i + 1)) > x)
            {
                ret = i;
                break;
            }
        }
        return ret;
    }
};

