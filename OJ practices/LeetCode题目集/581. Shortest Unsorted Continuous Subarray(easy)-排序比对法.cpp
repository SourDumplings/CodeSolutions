/*
 * @Autor: SourDumplings
 * @Date: 2019-10-06 10:28:46
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/shortest-unsorted-continuous-subarray/
 * 
 * 算法就是和有序版本进行比对，空间复杂度O(n)，时间复杂度O(nlogn)
 */

class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int n = nums.size();
        int f = 1, l = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != temp[i])
            {
                f = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (nums[i] != temp[i])
            {
                l = i;
                break;
            }
        }

        return l - f + 1;
    }
};