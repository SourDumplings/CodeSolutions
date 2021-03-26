/*
 * @Author: SourDumplings
 * @Date: 2021-03-26 22:30:28
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/wiggle-sort-ii/
 */

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int temp;
        vector<int> res(n);
        // 由于可能出现两个子数组有重复数字的情况，故从后往前遍历
        // 因为重复数字一定是相邻的，例如 [1 1 2 2 2 3]，
        // 两个子数组为 [1 1 2] 和 [2 2 3]
        // 重复数字的个数不可能多于 n / 2，否则题目无解
        int first = n % 2 == 0 ? n / 2 - 1 : n / 2;
        int second = n - 1;
        for (int i = 0; i < n; ++i)
        {
            if (i % 2 == 0)
            {
                res[i] = nums[first--];
            }
            else
            {
                res[i] = nums[second--];
            }
        }
        nums = res;
    }
};