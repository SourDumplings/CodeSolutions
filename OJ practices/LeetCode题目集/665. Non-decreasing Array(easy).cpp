/*
 * @Autor: SourDumplings
 * @Date: 2019-10-13 08:53:13
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/non-decreasing-array/
 * 
 * 顺序扫描数组，遇到nums[i] > nums[i+1]时，分为两种情况：
 * 1.nums[i+1]大于等于nums[i-1]，此时只需要将nums[i]降为nums[i+1]即可
 * 如：1 2 3 5 4 6 7
 * 2.nums[i+1]小于nums[i-1]，这是需要将nums[i+1]升为nums[i]
 * 如：1 2 4 5 3 6 7
 * 如果需要第二次操作则返回false
 */

class Solution
{
public:
    bool checkPossibility(vector<int> &nums)
    {
        bool flag = true;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] > nums[i + 1])
            {
                if (flag)
                {
                    flag = false;
                    if (i == 0 || nums[i - 1] <= nums[i + 1])
                    {
                        nums[i] = nums[i + 1];
                    }
                    else
                    {
                        nums[i + 1] = nums[i];
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};