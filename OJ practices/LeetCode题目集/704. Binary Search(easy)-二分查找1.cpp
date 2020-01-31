/*
 * @Author: SourDumplings
 * @Date: 2019-10-24 10:24:37
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-search/
 */

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            if (nums[mi] == target)
            {
                return mi;
            }
            else if (nums[mi] < target)
            {
                lo = mi + 1;
            }
            else
            {
                hi = mi;
            }
        }
        if (nums[lo] == target)
        {
            return lo;
        }
        else
        {
            return -1;
        }
    }
};