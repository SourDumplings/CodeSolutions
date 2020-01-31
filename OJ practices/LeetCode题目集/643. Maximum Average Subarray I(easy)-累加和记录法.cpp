/*
 * @Author: SourDumplings
 * @Date: 2019-10-11 17:35:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/maximum-average-subarray-i/
 * 
 * 用一个数组记录前缀子列的和，比如sum[i]代表nums[0]~nums[i - 1]的和
 * 然后要求哪个子列就作差即可。
 * 再扫描一遍sum，即可得到最大平均数
 */

class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> sum;
        sum.resize(n + 1);
        sum[0] = 0;
        sum[1] = nums[0];
        for (int i = 2; i <= n; i++)
        {
            sum[i] = sum[i - 1] + nums[i - 1];
        }
        int maxSum = -2147483648;
        for (int i = 0; i <= n - k; i++)
        {
            if (sum[i + k] - sum[i] > maxSum)
            {
                maxSum = sum[i + k] - sum[i];
            }
        }
        return (double)maxSum / k;
    }
};