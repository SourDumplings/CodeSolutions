/*
 * @Autor: SourDumplings
 * @Date: 2019-09-27 14:40:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/max-consecutive-ones/
 */

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int res = 0;
        int leftMost = -1;
        bool isOnes = false;
        int l = nums.size();
        for (int i = 0; i < l; i++)
        {
            if (nums[i] == 1)
            {
                if (!isOnes)
                {
                    leftMost = i;
                    isOnes = true;
                }
            }
            else if (isOnes)
            {
                isOnes = false;
                if (i - leftMost > res)
                {
                    res = i - leftMost;
                }
            }
        }
        if (isOnes && l - leftMost > res)
        {
            res = l - leftMost;
        }
        return res;
    }
};