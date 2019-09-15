/*
 * @Autor: SourDumplings
 * @Date: 2019-09-15 13:10:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/valid-perfect-square/
 * 
 * 使用二分查找即可
 */

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        long long lo = 0, hi = num;
        while (lo < hi)
        {
            long long mi = (lo + hi) / 2;
            long long r = mi * mi;
            if (r == num)
                return true;
            else if (r < num)
            {
                lo = mi + 1;
            }
            else
            {
                hi = mi;
            }
        }
        return lo * lo == num;
    }
};
