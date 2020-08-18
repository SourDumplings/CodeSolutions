/*
 * @Author: SourDumplings
 * @Date: 2020-08-12 17:12:25
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
 */

class Solution
{
    public int removeDuplicates(int[] nums)
    {
        int l = nums.length;
        if (l == 0)
        {
            return 0;
        }
        int last = nums[0];
        int count = 1;
        int invalidNum = nums[0] - 1;
        for (int i = 1; i < l; i++)
        {
            if (nums[i] == last)
            {
                if (count == 2)
                {
                    nums[i] = invalidNum;
                }
                else
                {
                    ++count;
                }
            }
            else
            {
                last = nums[i];
                count = 1;
            }
        }
        int p = 0;
        for (int i = 0; i < l; ++i)
        {
            if (nums[i] != invalidNum)
            {
                nums[p++] = nums[i];
            }
        }
        return p;
    }
}
