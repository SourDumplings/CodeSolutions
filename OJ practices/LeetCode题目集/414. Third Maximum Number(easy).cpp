/*
 * @Author: SourDumplings
 * @Date: 2019-09-24 15:17:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/third-maximum-number/
 */

#include <climits>

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        int f = INT_MIN, s = INT_MIN, t = INT_MIN;
        for (auto &&i : nums)
        {
            if (i > f)
            {
                f = i;
            }
        }
        for (auto &&i : nums)
        {
            if (i > s && i < f)
            {
                s = i;
            }
        }
        bool hasT = false;
        for (auto &&i : nums)
        {
            if (i >= t && i < s)
            {
                hasT = true;
                t = i;
            }
        }
        return hasT ? t : f;
    }
};