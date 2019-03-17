/*
 @Date    : 2019-01-17 17:45:06
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/maximum-subarray/
 */

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int thisSum = 0, maxSum = 0;
        bool isFirst = true;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (isFirst)
            {
                maxSum = thisSum = nums[0];
                isFirst = false;
            }
            else
            {
                if (nums[i] >= maxSum && maxSum < 0)
                {
                    thisSum = maxSum = nums[i];
                }
                else if (thisSum + nums[i] < 0 && maxSum >= 0)
                {
                    thisSum = 0;
                }
                else
                {
                    thisSum += nums[i];
                    if (thisSum > maxSum)
                    {
                        maxSum = thisSum;
                    }
                }
            }
        }
        return maxSum;
    }
};
