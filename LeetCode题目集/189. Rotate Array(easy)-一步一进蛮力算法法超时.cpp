/*
 * @Author: SourDumplings
 * @Date: 2019-07-20 16:36:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/rotate-array/
 */

/* 一步一进的方法，空间复杂度O(1)，时间复杂度O(kn) */

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        int s = k % n;
        while (s--)
        {
            move_one_step(nums, n);
        }
    }
    void move_one_step(vector<int> &nums, int n)
    {
        int x = nums[n - 1];
        for (int i = n - 1; i > 0; --i)
        {
            nums[i] = nums[i - 1];
        }
        nums[0] = x;
    }
};