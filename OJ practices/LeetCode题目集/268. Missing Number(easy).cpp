/*
 * @Author: SourDumplings
 * @Date: 2019-09-02 21:00:00
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/missing-number/
 */

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        return (0 + n) * (n + 1) / 2 - s;
    }
};