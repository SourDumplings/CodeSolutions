/*
 * @Author: SourDumplings
 * @Date: 2020-02-16 17:22:32
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/first-missing-positive/
 * 
 * 该题的做法就是先把非正数都变成1
 * 然后用负号来标记该位置的元素是存在的，即用正负号来当 bit，自己作为 bitmap
 */

class Solution
{
    public int firstMissingPositive(int[] nums)
    {
        int l = nums.length;
        boolean hasOne = false;
        for (int i = 0; i < l; i++)
        {
            if (nums[i] == 1)
            {
                hasOne = true;
            }
            else if (nums[i] < 1)
            {
                nums[i] = 1;
            }
        }

        // 如果原数组中没有1，那么结果就是1
        if (!hasOne)
        {
            return 1;
        }

        for (int i = 0; i < l; i++)
        {
            int num = nums[i];
            if (num < 0)
            {
                num *= -1;
            }
            if (num <= l && 0 < nums[num - 1])
            {
                nums[num - 1] *= -1;
            }
        }

        for (int i = 0; i < l; i++)
        {
            if (0 < nums[i])
            {
                return i + 1;
            }
        }
        return l + 1;
    }
}