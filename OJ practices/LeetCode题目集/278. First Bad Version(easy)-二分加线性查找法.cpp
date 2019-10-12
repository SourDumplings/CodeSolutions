/*
 * @Author: SourDumplings
 * @Date: 2019-09-03 20:55:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/first-bad-version/
 */

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        while (isBadVersion(n))
        {
            n /= 2;
        }
        while (!isBadVersion(n))
        {
            ++n;
        }
        return n;
    }
};