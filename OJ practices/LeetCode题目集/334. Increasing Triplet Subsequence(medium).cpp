/*
 * @Author: SourDumplings
 * @Date: 2021-04-04 10:32:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/increasing-triplet-subsequence/

 使用双指针，记录扫描过的最小和第二小的数
 */

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            return false;
        }
        int minV = INT32_MAX, midV = INT32_MAX;
        for (int num : nums)
        {
            if (num <= minV)
            {
                minV = num;
            }
            else if (num <= midV)
            {
                midV = num;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};