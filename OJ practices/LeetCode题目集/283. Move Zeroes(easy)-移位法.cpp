/*
 * @Author: SourDumplings
 * @Date: 2019-09-05 21:45:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/move-zeroes/
 */

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                nums[j++] = nums[i];
            }
        }
        fill(nums.begin() + j, nums.end(), 0);
    }
};