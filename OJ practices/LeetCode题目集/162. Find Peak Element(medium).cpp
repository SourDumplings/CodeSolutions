/*
 * @Author: SourDumplings
 * @Date: 2020-12-04 20:40:16
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/find-peak-element/
 */

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            if (nums[mi] > nums[mi + 1])
            {
                hi = mi;
            }
            else
            {
                lo = mi + 1;
            }
        }
        return lo;
    }
};