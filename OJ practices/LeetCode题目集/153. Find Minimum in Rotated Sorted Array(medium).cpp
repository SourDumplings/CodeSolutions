/*
 * @Author: SourDumplings
 * @Date: 2020-12-01 23:32:30
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
 */

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size();
        int lo = 0, hi = n - 1;
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            if (nums[mi] <= nums[hi])
            {
                hi = mi;
            }
            else
            {
                lo = mi + 1;
            }
        }
        return nums[lo];
    }

};