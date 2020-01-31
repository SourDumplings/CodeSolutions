/*
 * @Author: SourDumplings
 * @Date: 2019-10-14 07:53:50
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
 */

class Solution
{
public:
    int findLengthOfLCIS(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }

        int thisStart = 0, res = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i + 1] <= nums[i])
            {
                if (i + 1 - thisStart > res)
                {
                    res = i + 1 - thisStart;
                }
                thisStart = i + 1;
            }
        }
        if (n - thisStart > res)
        {
            res = n - thisStart;
        }

        return res;
    }
};