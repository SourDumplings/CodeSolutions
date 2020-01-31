/*
 * @Author: SourDumplings
 * @Date: 2019-10-05 09:16:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/array-partition-i/
 */

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int res = 0;
        int n = nums.size();
        for (int i = 0; i < n; i += 2)
        {
            res += min(nums[i], nums[i + 1]);
        }
        return res;
    }
};