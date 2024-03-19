/**
 * @file 189. Rotate Array(medium)-翻转数组法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 翻转三次数组即可实现右移位空间
 * 复杂度：O(1)，时间 O(n)
 * 
 * https://leetcode.cn/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k %= n;
        if (k == 0)
        {
            return;
        }
        
        reverse(nums, 0, n);
        reverse(nums, 0, k);
        reverse(nums, k, n);
    }

private:
    void reverse(vector<int> &nums, int b, int e)
    {
        for (int i = b; i < (e + b) / 2; ++i)
        {
            int temp = nums[i];
            nums[i] = nums[e - (i - b) - 1];
            nums[e - (i - b) - 1] = temp;
        }
    }
};