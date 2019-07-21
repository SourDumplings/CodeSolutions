/*
 * @Author: SourDumplings
 * @Date: 2019-07-20 16:36:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/rotate-array/
 */

/* 重读法，另开一个数组，时间和空间复杂度都是O(n) */

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        int s = k % n;
        vector<int> nums_copy(nums);
        for (int i = 0; i < n; i++)
        {
            nums[(i + s) % n] = nums_copy[i];
        }
    }
};