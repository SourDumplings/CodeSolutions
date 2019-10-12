/*
 * @Author: SourDumplings
 * @Date: 2019-09-03 21:04:10
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/first-bad-version/
 */

/* The isBadVersion API is defined in the parent class VersionControl.
     boolean isBadVersion(int version); */

public class Solution extends VersionControl
{
    public int firstBadVersion(int n)
    {
        int lo = 0;
        int hi = n;
        while (lo < hi)
        {
            int mi = lo + (hi - lo) / 2; // 换成(lo + hi) / 2会超时
            if (isBadVersion(mi))
            {
                hi = mi;
            }
            else
            {
                lo = mi + 1; // lo如果为mi会导致死循环，比如lo = 3，hi = 4，并且isBadVersion(3)是false
            }
        }
        return lo;
    }
}