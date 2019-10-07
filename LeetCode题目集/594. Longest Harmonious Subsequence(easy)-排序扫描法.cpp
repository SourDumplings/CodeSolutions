/*
 * @Autor: SourDumplings
 * @Date: 2019-10-07 21:56:49
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-harmonious-subsequence/
 */

class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        int thisStart = 0, endStart = 0;
        int n = nums.size();
        for (int i = 1; i < n;)
        {
            if (nums[i] == nums[thisStart] || nums[i] == nums[thisStart] + 1)
            {
                while (i < n &&
                       (nums[i] == nums[thisStart] || nums[i] == nums[thisStart] + 1))
                {
                    if (nums[i] == nums[i - 1] + 1)
                    {
                        endStart = i;
                    }
                    ++i;
                }
                if (nums[i - 1] == nums[thisStart] + 1)
                {
                    if (i - thisStart > res)
                    {
                        res = i - thisStart;
                    }
                    thisStart = endStart;
                }
            }
            else
            {
                thisStart = i++;
            }
        }
        return res;
    }
};