/*
 * @Author: SourDumplings
 * @Date: 2019-07-20 16:36:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/rotate-array/
 */

/* 循环移位法，需要一个空位，用一个临时变量存储空位，时间复杂度为O(n)，空间复杂度O(1) */

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        int s = k % n;
        int temp = 0, count = 0, i = 0, j = 0;
        while (count < n)
        {
            swap(nums[i], temp);
            do
            {
                swap(nums[j = ((j + s) % n)], temp);
                ++count;
            } while (i != j);
            ++i;
            j = i;
        }
    }
};
